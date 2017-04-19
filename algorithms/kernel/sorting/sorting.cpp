/* file: sorting.cpp */
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
//  Implementation of sorting algorithm and types methods.
//--
*/

#include "sorting_types.h"
#include "serialization_utils.h"

using namespace daal::data_management;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace sorting
{
namespace interface1
{

__DAAL_REGISTER_SERIALIZATION_CLASS(Result, SERIALIZATION_SORTING_RESULT_ID);
Input::Input() : daal::algorithms::Input(1) {}
Input::Input(const Input& other) : daal::algorithms::Input(other){}

/**
 * Returns an input object for the sorting algorithm
 * \param[in] id    Identifier of the %input object
 * \return          %Input object that corresponds to the given identifier
 */
data_management::NumericTablePtr Input::get(InputId id) const
{
    return services::staticPointerCast<data_management::NumericTable, data_management::SerializationIface>(Argument::get(id));
}

/**
 * Sets the input object of the sorting algorithm
 * \param[in] id    Identifier of the %input object
 * \param[in] ptr   Pointer to the input object
 */
void Input::set(InputId id, const data_management::NumericTablePtr &ptr)
{
    Argument::set(id, ptr);
}

/**
 * Check the correctness of the %Input object
 * \param[in] method    Algorithm computation method
 * \param[in] par       Pointer to the parameters of the algorithm
 */
Status Input::check(const Parameter *par, int method) const
{
    int unexpectedLayouts = data_management::packed_mask;
    Status s = data_management::checkNumericTable(get(data).get(), dataStr(), unexpectedLayouts);
    return s;
}

Result::Result() : daal::algorithms::Result(1) {}

/**
 * Returns the final result of the sorting algorithm
 * \param[in] id   Identifier of the final result, \ref ResultId
 * \return         Final result that corresponds to the given identifier
 */
data_management::NumericTablePtr Result::get(ResultId id) const
{
    return services::staticPointerCast<data_management::NumericTable, data_management::SerializationIface>(Argument::get(id));
}

/**
 * Sets the Result object of the sorting algorithm
 * \param[in] id        Identifier of the Result object
 * \param[in] value     Pointer to the Result object
 */
void Result::set(ResultId id, const data_management::NumericTablePtr &value)
{
    Argument::set(id, value);
}

/**
 * Checks the correctness of the Result object
 * \param[in] in     Pointer to the object
 * \param[in] par     %Parameter of algorithm
 * \param[in] method Algorithm computation method
 */
Status Result::check(const daal::algorithms::Input *in, const Parameter *par, int method) const
{
    const Input *input = static_cast<const Input *>(in);

    size_t nFeatures = input->get(data)->getNumberOfColumns();
    size_t nVectors  = input->get(data)->getNumberOfRows();
    int unexpectedLayouts = data_management::packed_mask;

    Status s = data_management::checkNumericTable(get(sortedData).get(), sortedDataStr(), unexpectedLayouts, 0, nFeatures, nVectors);
    return s;
}

}// namespace interface1
}// namespace sorting
}// namespace algorithms
}// namespace daal