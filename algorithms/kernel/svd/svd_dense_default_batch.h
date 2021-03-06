/* file: svd_dense_default_batch.h */
/*******************************************************************************
* Copyright 2014-2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of svd algorithm and types methods.
//--
*/
#ifndef __SVD_DENSE_DEFAULT_BATCH__
#define __SVD_DENSE_DEFAULT_BATCH__

#include "svd_types.h"

namespace daal
{
namespace algorithms
{
namespace svd
{
namespace interface1
{

/**
 * Allocates memory to store final results of the SVD algorithm
 * \param[in] input     Pointer to the input object
 * \param[in] parameter Pointer to the parameter
 * \param[in] method    Algorithm computation method
 */
template <typename algorithmFPType>
DAAL_EXPORT void Result::allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method)
{
    const Input *in = static_cast<const Input *>(input);
    allocateImpl<algorithmFPType>(in->get(data)->getNumberOfColumns(), in->get(data)->getNumberOfRows());
}

/**
 * Allocates memory to store final results of the SVD algorithm
 * \param[in] partialResult  Pointer to the partial result
 * \param[in] parameter      Pointer to the parameter
 * \param[in] method         Algorithm computation method
 */
template <typename algorithmFPType>
DAAL_EXPORT void Result::allocate(const daal::algorithms::PartialResult *partialResult, daal::algorithms::Parameter *parameter,
              const int method)
{
    const OnlinePartialResult *in = static_cast<const OnlinePartialResult *>(partialResult);
    allocateImpl<algorithmFPType>(in->getNumberOfColumns(), in->getNumberOfRows());
}

/**
 * Allocates memory to store final results of the SVD algorithm
 * \tparam     algorithmFPType  Data type to use for storage in the resulting HomogenNumericTable
 * \param[in]  m  Number of columns in the input data set
 * \param[in]  n  Number of rows in the input data set
 */
template <typename algorithmFPType>
DAAL_EXPORT void Result::allocateImpl(size_t m, size_t n)
{
    Argument::set(singularValues, data_management::SerializationIfacePtr(
                      new data_management::HomogenNumericTable<algorithmFPType>(m, 1, data_management::NumericTable::doAllocate)));
    Argument::set(rightSingularMatrix, data_management::SerializationIfacePtr(
                      new data_management::HomogenNumericTable<algorithmFPType>(m, m, data_management::NumericTable::doAllocate)));
    if(n != 0)
    {
        Argument::set(leftSingularMatrix, data_management::SerializationIfacePtr(
                          new data_management::HomogenNumericTable<algorithmFPType>(m, n, data_management::NumericTable::doAllocate)));
    }
}

}// namespace interface1
}// namespace svd
}// namespace algorithms
}// namespace daal

#endif
