/* file: kernel_function_linear.cpp */
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
//  Implementation of kernel function algorithm and types methods.
//--
*/

#include "kernel_function_types_linear.h"

using namespace daal::data_management;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace kernel_function
{
namespace linear
{
namespace interface1
{
Parameter::Parameter(double k, double b) : ParameterBase(), k(k), b(b) {}

Input::Input() : kernel_function::Input() {}

/**
* Checks input objects of the kernel function linear algorithm
* \param[in] par     %Input objects of the algorithm
* \param[in] method  Computation method of the algorithm
*/
services::Status Input::check(const daal::algorithms::Parameter *par, int method) const
{
    services::Status s;
    if(method == fastCSR)
    {
        DAAL_CHECK_STATUS(s, checkCSR());
    }
    else
    {
        DAAL_CHECK_STATUS(s, checkDense());
    }
    return s;
}

}// namespace interface1
}// namespace linear
}// namespace kernel_function
}// namespace algorithms
}// namespace daal