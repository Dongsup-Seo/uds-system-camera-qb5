////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2019 Qualcomm Technologies, Inc.
/// All Rights Reserved.
/// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CHIFEATURE2TESTREQUESTOBJECT_H
#define CHIFEATURE2TESTREQUESTOBJECT_H

#include "chifeature2test.h"

class ChiFeature2TestRequestObject
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ChiFeature2TestRequestObject
    ///
    /// @param pTest    The test that will be used to check and assert conditions.
    ///
    /// @brief Default constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ChiFeature2TestRequestObject(
        ChiFeature2Test* pTest);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ~ChiFeature2TestRequestObject
    ///
    /// @brief Default destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ~ChiFeature2TestRequestObject()=default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// RunInitAndDestroyTests
    ///
    /// @brief main business logic to run the test
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void RunInitAndDestroyTests();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// RunBasicCallFlow
    ///
    /// @brief main business logic to run the test
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void RunBasicCallFlow();

private:
    ChiFeature2Test*        m_pTest;                        ///< Test object
};

#endif // CHIFEATURE2TESTREQUESTOBJECT_H