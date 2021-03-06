/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkMutualInformationHistogramImageToImageMetric_h
#define itkMutualInformationHistogramImageToImageMetric_h

#include "itkHistogramImageToImageMetric.h"

namespace itk
{
/** \class MutualInformationHistogramImageToImageMetric
 * \brief Computes the mutual information between two images to be
 * registered using the histograms of the intensities in the images.
 * This class is templated over the type of the fixed and moving
 * images to be compared.
 *
 * This metric computes the similarity measure between pixels in the
 * moving image and pixels in the fixed images using a histogram.
 *
 * \ingroup RegistrationMetrics
 * \ingroup ITKRegistrationCommon
 */
template< typename TFixedImage, typename TMovingImage >
class ITK_TEMPLATE_EXPORT MutualInformationHistogramImageToImageMetric:
  public HistogramImageToImageMetric< TFixedImage, TMovingImage >
{
public:
  ITK_DISALLOW_COPY_AND_ASSIGN(MutualInformationHistogramImageToImageMetric);

  /** Standard class type aliases. */
  using Self = MutualInformationHistogramImageToImageMetric;
  using Superclass = HistogramImageToImageMetric< TFixedImage, TMovingImage >;
  using Pointer = SmartPointer< Self >;
  using ConstPointer = SmartPointer< const Self >;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(MutualInformationHistogramImageToImageMetric,
               HistogramImageToImageMetric);

  /** Types transferred from the base class */
  using RealType = typename Superclass::RealType;
  using TransformType = typename Superclass::TransformType;
  using TransformPointer = typename Superclass::TransformPointer;
  using TransformParametersType = typename Superclass::TransformParametersType;
  using TransformJacobianType = typename Superclass::TransformJacobianType;
  using GradientPixelType = typename Superclass::GradientPixelType;

  using MeasureType = typename Superclass::MeasureType;
  using DerivativeType = typename Superclass::DerivativeType;
  using FixedImageType = typename Superclass::FixedImageType;
  using MovingImageType = typename Superclass::MovingImageType;
  using FixedImageConstPointer = typename Superclass::FixedImageConstPointer;
  using MovingImageConstPointer = typename Superclass::MovingImageConstPointer;

  using HistogramType = typename Superclass::HistogramType;
  using HistogramFrequencyType = typename HistogramType::AbsoluteFrequencyType;
  using HistogramIteratorType = typename HistogramType::Iterator;
  using HistogramMeasurementVectorType = typename HistogramType::MeasurementVectorType;

protected:
  /** Constructor is protected to ensure that \c New() function is used to
      create instances. */
  MutualInformationHistogramImageToImageMetric(){}
  ~MutualInformationHistogramImageToImageMetric() override {}

  /** Evaluates the mutual information from the histogram. */
  MeasureType EvaluateMeasure(HistogramType & histogram) const override;
};
} // End namespace itk.

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkMutualInformationHistogramImageToImageMetric.hxx"
#endif

#endif // itkMutualInformationHistogramImageToImageMetric_h
