/* file: SingleBetaDataInputId.java */
/*******************************************************************************
* Copyright 2014-2016 Intel Corporation
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

package com.intel.daal.algorithms.linear_regression.quality_metric;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__LINEAR_REGRESSION__QUALITY_METRIC__SINGLEBETADATAINPUTID"></a>
 * @brief Available identifiers of input objects for a single beta quality metrics
 */
public final class SingleBetaDataInputId {
    private int _value;

    public SingleBetaDataInputId(int value) {
        _value = value;
    }

    public int getValue() {
        return _value;
    }

    private static final int ExpectedResponses   = 0;
    private static final int PredictedResponses = 1;

    /*!< Expected responses (Y), dependent variables */
    public static final SingleBetaDataInputId expectedResponses   = new SingleBetaDataInputId(ExpectedResponses);
    /*!< Predicted responses (Z) */
    public static final SingleBetaDataInputId predictedResponses = new SingleBetaDataInputId(PredictedResponses);
}