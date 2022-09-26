#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiColor.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/S/SkyObject.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class BSGeometry;
	class NiTexture;

	class Clouds :
		public SkyObject // 0
	{
	public:
		enum class Layer
		{
			kTotal = 32
		};

		// Override
		virtual ~Clouds() override; // 0

		// Override (SkyObject)
		virtual void Unknown2(SkyObject*) override; // 2
		virtual void Unknown3(SkyObject*) override; // 3

		// Member variables
		NiPointer<BSGeometry> clouds[Utility::ToUnderlying(Layer::kTotal)];             // 10
		std::uint64_t         unknown110[Utility::ToUnderlying(Layer::kTotal)];         // 110
		NiPointer<NiTexture>  transitionTextures[Utility::ToUnderlying(Layer::kTotal)]; // 210
		NiColor               colors[Utility::ToUnderlying(Layer::kTotal)];             // 310
		float                 alphas[Utility::ToUnderlying(Layer::kTotal)];             // 490
		std::uint16_t         layerCount;                                               // 510
		bool                  forceUpdate;                                              // 512
		std::uint8_t          unknown513;                                               // 513
		std::uint32_t         padding514;                                               // 514
		std::uint64_t         unknown518;                                               // 518
	};
	static_assert(offsetof(Clouds, clouds) == 0x10);
	static_assert(offsetof(Clouds, transitionTextures) == 0x210);
	static_assert(offsetof(Clouds, colors) == 0x310);
	static_assert(offsetof(Clouds, alphas) == 0x490);
	static_assert(offsetof(Clouds, layerCount) == 0x510);
	static_assert(offsetof(Clouds, forceUpdate) == 0x512);
	static_assert(sizeof(Clouds) == 0x520);
}
