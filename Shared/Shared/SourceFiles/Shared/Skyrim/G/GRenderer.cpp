#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRenderer.h"



namespace Skyrim
{
	GRenderer::StereoParameters::StereoParameters() :
		displayWidthCentimeters(0.0F),
		distortion(0.75F),
		displayDiagonalInches(52.0F),
		displayAspectRatio(9.0F / 16.0F),
		eyeSeparationCentimeters(6.4F)
	{
	}

	GRenderer::Statistics::Statistics()
	{
		this->Clear();
	}

	GRenderer::UserData::UserData() :
		string(nullptr),
		number(nullptr),
		matrix(nullptr),
		matrixSize(0),
		propertyFlags(UserDataPropertyFlag::kNone)
	{
	}

	void GRenderer::Statistics::Clear()
	{
		this->triangles  = 0;
		this->lines      = 0;
		this->primitives = 0;
		this->masks      = 0;
		this->filters    = 0;
	}

	GRenderer* GRenderer::CachedData::GetRenderer() const
	{
		return this->renderer_;
	}

	GRenderer::Handle GRenderer::CachedData::GetRendererData() const
	{
		return this->data_;
	}

	void GRenderer::CachedData::SetRendererData(Handle data)
	{
		this->data_ = data;
	}

	bool GRenderer::CacheProvider::CanDiscardData()
	{
		return this->discardSharedData_;
	}

	bool GRenderer::Cxform::operator==(const Cxform& right) const
	{
		return this->elements[Utility::Conversion::ToUnderlying(Color::kRed)][Utility::Conversion::ToUnderlying(Operation::kMultiply)] ==
		           right.elements[Utility::Conversion::ToUnderlying(Color::kRed)][Utility::Conversion::ToUnderlying(Operation::kMultiply)] &&
		       this->elements[Utility::Conversion::ToUnderlying(Color::kGreen)][Utility::Conversion::ToUnderlying(Operation::kMultiply)] ==
		           right.elements[Utility::Conversion::ToUnderlying(Color::kGreen)][Utility::Conversion::ToUnderlying(Operation::kMultiply)] &&
		       this->elements[Utility::Conversion::ToUnderlying(Color::kBlue)][Utility::Conversion::ToUnderlying(Operation::kMultiply)] ==
		           right.elements[Utility::Conversion::ToUnderlying(Color::kBlue)][Utility::Conversion::ToUnderlying(Operation::kMultiply)] &&
		       this->elements[Utility::Conversion::ToUnderlying(Color::kAlpha)][Utility::Conversion::ToUnderlying(Operation::kMultiply)] ==
		           right.elements[Utility::Conversion::ToUnderlying(Color::kAlpha)][Utility::Conversion::ToUnderlying(Operation::kMultiply)] &&
		       this->elements[Utility::Conversion::ToUnderlying(Color::kRed)][Utility::Conversion::ToUnderlying(Operation::kAdd)] ==
		           right.elements[Utility::Conversion::ToUnderlying(Color::kRed)][Utility::Conversion::ToUnderlying(Operation::kAdd)] &&
		       this->elements[Utility::Conversion::ToUnderlying(Color::kGreen)][Utility::Conversion::ToUnderlying(Operation::kAdd)] ==
		           right.elements[Utility::Conversion::ToUnderlying(Color::kGreen)][Utility::Conversion::ToUnderlying(Operation::kAdd)] &&
		       this->elements[Utility::Conversion::ToUnderlying(Color::kBlue)][Utility::Conversion::ToUnderlying(Operation::kAdd)] ==
		           right.elements[Utility::Conversion::ToUnderlying(Color::kBlue)][Utility::Conversion::ToUnderlying(Operation::kAdd)] &&
		       this->elements[Utility::Conversion::ToUnderlying(Color::kAlpha)][Utility::Conversion::ToUnderlying(Operation::kAdd)] ==
		           right.elements[Utility::Conversion::ToUnderlying(Color::kAlpha)][Utility::Conversion::ToUnderlying(Operation::kAdd)];
	}

	bool GRenderer::BlurFilterParameters::operator==(const BlurFilterParameters& right) const
	{
		return this->mode == right.mode && this->blurX == right.blurX && this->blurY == right.blurY && this->passes == right.passes;
	}
}
