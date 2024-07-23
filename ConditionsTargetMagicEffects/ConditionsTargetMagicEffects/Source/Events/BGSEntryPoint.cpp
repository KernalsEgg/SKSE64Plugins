#include "PrecompiledHeader.h"

#include "Events/BGSEntryPoint.h"

#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void BGSEntryPoint::Register()
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Skyrim::Addresses::BGSEntryPoint::HandleEntryPoint(),
			reinterpret_cast<std::uintptr_t>(std::addressof(BGSEntryPoint::HandleEntryPoint)));
	}

	/* Dynamically allocate memory on the heap using vectors instead of statically allocating memory on the stack using arrays so that any number of arguments can be sent */
	void BGSEntryPoint::HandleEntryPoint(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...)
	{
		if (entryPoint.underlying() < Utility::Conversion::ToUnderlying(Skyrim::BGSEntryPoint::EntryPoint::kTotal))
		{
			if (perkOwner && perkOwner->HasPerkEntries(entryPoint.get()))
			{
				auto conditionFilterArgumentCount    = Skyrim::BGSEntryPoint::GetEntryPoint(entryPoint)->conditionFilterArgumentCount;
				auto entryPointFunctionType          = Skyrim::BGSEntryPoint::GetEntryPoint(entryPoint)->entryPointFunctionType;
				auto entryPointFunctionArgumentCount = Skyrim::BGSEntryPointFunction::GetEntryPointFunctionArgumentCount(entryPointFunctionType.get());

				std::va_list variadicArguments;
				va_start(variadicArguments, perkOwner);

				std::vector<Skyrim::TESForm*> conditionFilterArguments;
				conditionFilterArguments.push_back(perkOwner);

				for (std::size_t conditionFilterArgumentIndex = 1;
					 conditionFilterArgumentIndex < conditionFilterArgumentCount;
					 ++conditionFilterArgumentIndex)
				{
					conditionFilterArguments.push_back(va_arg(variadicArguments, Skyrim::TESForm*));
				}

				std::vector<void*> entryPointFunctionArguments;

				for (std::size_t entryPointFunctionArgumentIndex = 0;
					 entryPointFunctionArgumentIndex < entryPointFunctionArgumentCount;
					 ++entryPointFunctionArgumentIndex)
				{
					entryPointFunctionArguments.push_back(va_arg(variadicArguments, void*));
				}

				if (std::none_of(entryPointFunctionArguments.begin(), entryPointFunctionArguments.end(), std::logical_not{}))
				{
					Skyrim::HandleEntryPointVisitor handleEntryPointVisitor(
						entryPointFunctionType.get(),
						conditionFilterArguments.empty() ? nullptr : conditionFilterArguments.data(),
						entryPointFunctionArguments.empty() ? nullptr : entryPointFunctionArguments.data(),
						perkOwner,
						static_cast<std::uint8_t>(conditionFilterArguments.size()),
						static_cast<std::uint8_t>(entryPointFunctionArguments.size()));

					perkOwner->ForEachPerkEntry(entryPoint.get(), handleEntryPointVisitor);
				}
				else
				{
					auto effectSettingCount = std::count_if(
						conditionFilterArguments.begin(),
						conditionFilterArguments.end(),
						[](auto* form) -> bool
						{
							return form && form->formType == Skyrim::FormType::kMagicEffect;
						});

					for (std::size_t conditionFilterArgumentIndex = conditionFilterArgumentCount;
						 std::cmp_less(conditionFilterArgumentIndex, conditionFilterArgumentCount + effectSettingCount);
						 ++conditionFilterArgumentIndex)
					{
						conditionFilterArguments.push_back(va_arg(variadicArguments, Skyrim::TESForm*));
					}

					entryPointFunctionArguments.clear();

					for (std::size_t entryPointFunctionArgumentIndex = 0;
						 entryPointFunctionArgumentIndex < entryPointFunctionArgumentCount;
						 ++entryPointFunctionArgumentIndex)
					{
						entryPointFunctionArguments.push_back(va_arg(variadicArguments, void*));
					}

					if (std::none_of(entryPointFunctionArguments.begin(), entryPointFunctionArguments.end(), std::logical_not{}))
					{
						Skyrim::HandleEntryPointVisitor handleEntryPointVisitor(
							entryPointFunctionType.get(),
							conditionFilterArguments.empty() ? nullptr : conditionFilterArguments.data(),
							entryPointFunctionArguments.empty() ? nullptr : entryPointFunctionArguments.data(),
							perkOwner,
							static_cast<std::uint8_t>(conditionFilterArguments.size()),
							static_cast<std::uint8_t>(entryPointFunctionArguments.size()));

						perkOwner->ForEachPerkEntry(entryPoint.get(), handleEntryPointVisitor);
					}

					*va_arg(variadicArguments, bool*) = true;
				}

				va_end(variadicArguments);
			}
		}
	}
}
