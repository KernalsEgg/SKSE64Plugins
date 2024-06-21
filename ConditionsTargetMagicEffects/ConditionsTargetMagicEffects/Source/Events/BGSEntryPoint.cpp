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

	/* Dynamically allocate memory on the heap using std::vector instead of statically allocating memory on the stack using arrays so that any number of arguments can be sent */
	void BGSEntryPoint::HandleEntryPoint(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...)
	{
		if (entryPoint.underlying() < Utility::Conversion::ToUnderlying(Skyrim::BGSEntryPoint::EntryPoint::kTotal))
		{
			if (perkOwner && perkOwner->HasPerkEntries(entryPoint.get()))
			{
				auto conditionFilterArgumentCount        = Skyrim::BGSEntryPoint::GetEntryPoint(entryPoint.get())->conditionFilterArgumentCount;
				auto entryPointFunctionType              = Skyrim::BGSEntryPoint::GetEntryPoint(entryPoint.get())->entryPointFunctionType;
				auto entryPointFunctionTypeArgumentCount = Skyrim::BGSEntryPointFunction::GetEntryPointFunctionTypeArgumentCount(entryPointFunctionType.get());

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

				std::vector<void*> entryPointFunctionTypeArguments;

				for (std::size_t entryPointFunctionTypeArgumentIndex = 0;
					 entryPointFunctionTypeArgumentIndex < entryPointFunctionTypeArgumentCount;
					 ++entryPointFunctionTypeArgumentIndex)
				{
					entryPointFunctionTypeArguments.push_back(va_arg(variadicArguments, void*));
				}

				if (std::none_of(
						entryPointFunctionTypeArguments.begin(),
						entryPointFunctionTypeArguments.end(),
						[](void* entryPointFunctionTypeArgument) -> bool
						{
							return !entryPointFunctionTypeArgument;
						}))
				{
					Skyrim::HandleEntryPointVisitor handleEntryPointVisitor(
						entryPointFunctionType.get(),
						conditionFilterArguments.empty() ? nullptr : conditionFilterArguments.data(),
						entryPointFunctionTypeArguments.empty() ? nullptr : entryPointFunctionTypeArguments.data(),
						perkOwner,
						conditionFilterArgumentCount,
						entryPointFunctionTypeArgumentCount);

					perkOwner->ForEachPerkEntry(entryPoint.get(), handleEntryPointVisitor);
				}
				else
				{
					auto effectSettingCount = std::count_if(
						conditionFilterArguments.begin(),
						conditionFilterArguments.end(),
						[](Skyrim::TESForm* form)
						{
							return form && form->formType == Skyrim::FormType::kMagicEffect;
						});

					for (std::size_t conditionFilterArgumentIndex = conditionFilterArgumentCount;
						 std::cmp_less(conditionFilterArgumentIndex, conditionFilterArgumentCount + effectSettingCount);
						 ++conditionFilterArgumentIndex)
					{
						conditionFilterArguments.push_back(va_arg(variadicArguments, Skyrim::TESForm*));
					}

					entryPointFunctionTypeArguments.clear();

					for (std::size_t entryPointFunctionTypeArgumentIndex = 0;
						 entryPointFunctionTypeArgumentIndex < entryPointFunctionTypeArgumentCount;
						 ++entryPointFunctionTypeArgumentIndex)
					{
						entryPointFunctionTypeArguments.push_back(va_arg(variadicArguments, void*));
					}

					if (std::none_of(
							entryPointFunctionTypeArguments.begin(),
							entryPointFunctionTypeArguments.end(),
							[](void* entryPointFunctionTypeArgument) -> bool
							{
								return !entryPointFunctionTypeArgument;
							}))
					{
						Skyrim::HandleEntryPointVisitor handleEntryPointVisitor(
							entryPointFunctionType.get(),
							conditionFilterArguments.empty() ? nullptr : conditionFilterArguments.data(),
							entryPointFunctionTypeArguments.empty() ? nullptr : entryPointFunctionTypeArguments.data(),
							perkOwner,
							conditionFilterArgumentCount,
							entryPointFunctionTypeArgumentCount);

						perkOwner->ForEachPerkEntry(entryPoint.get(), handleEntryPointVisitor);
					}

					*va_arg(variadicArguments, bool*) = true;
				}

				va_end(variadicArguments);
			}
		}
	}
}
