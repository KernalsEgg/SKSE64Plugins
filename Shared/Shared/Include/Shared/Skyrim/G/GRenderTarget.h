#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAtomic.h"
#include "Shared/Skyrim/G/GNewOverrideBase.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Skyrim/G/GTexture.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	class GRenderer;

	class GRenderTarget :
		public GNewOverrideBase<Utility::Conversion::ToUnderlying(GStatisticRenderers::kMemory)> // 0
	{
	public:
		using ChangeHandler = GTexture::ChangeHandler;
		using Handle        = void*;

		// Add
		virtual ~GRenderTarget() {}                                         // 0
		virtual bool       InitializeRenderTarget(GTexture* target)    = 0; // 1
		virtual GRenderer* GetRenderer() const                         = 0; // 2
		virtual Handle     GetUserData() const                         = 0; // 3
		virtual void       SetUserData(Handle data)                    = 0; // 4
		virtual void       AddChangeHandler(ChangeHandler* handler)    = 0; // 5
		virtual void       RemoveChangeHandler(ChangeHandler* handler) = 0; // 6

		GRenderTarget();

		// Member functions
		void AddReference();
		bool AddReferenceNotZero();
		void Release();

	private:
		// Member variables
		GAtomicInteger<std::int32_t> referenceCount_; // 8
		std::uint32_t                paddingC_;       // C
	};
	static_assert(sizeof(GRenderTarget) == 0x10);
}
