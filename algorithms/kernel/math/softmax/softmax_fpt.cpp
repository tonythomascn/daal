/* file: softmax_fpt.cpp */
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
//  Implementation of softmax algorithm and types methods.
//--
*/

#include "softmax_types.h"

namespace daal
{
namespace algorithms
{
namespace math
{
namespace softmax
{
namespace interface1
{
/**
 * Allocates memory to store the results of the softmax function
 * \param[in] input  %Input object for the the softmax function
 * \param[in] par    %Parameter of the softmax function
 * \param[in] method Computation method of the softmax function
 */
template <typename algorithmFPType>
DAAL_EXPORT services::Status Result::allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, const int method)
{
    Input *algInput = static_cast<Input *>(const_cast<daal::algorithms::Input *>(input));

    if(algInput == 0) { return services::Status(services::ErrorNullInput); }
    if(algInput->get(data) == 0) { return services::Status(services::ErrorNullInputNumericTable); }
    if(algInput->get(data).get() == 0) { return services::Status(services::ErrorNullInputNumericTable); }

    size_t nFeatures     = algInput->get(data)->getNumberOfColumns();
    size_t nObservations = algInput->get(data)->getNumberOfRows();
    Argument::set(value, data_management::SerializationIfacePtr(
                      new data_management::HomogenNumericTable<algorithmFPType>(nFeatures, nObservations,
                                                                                data_management::NumericTable::doAllocate)));
    return services::Status();
}

template DAAL_EXPORT services::Status Result::allocate<DAAL_FPTYPE>(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, const int method);

}// namespace interface1
}// namespace softmax
}// namespace math
}// namespace algorithms
}// namespace daal