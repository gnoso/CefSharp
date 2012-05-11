#include "stdafx.h"
#pragma once

#include "IWebBrowser.h"
#include "RequestResponse.h"

using namespace System;
using namespace System::IO;

namespace CefSharp
{
    public interface class IBeforeResourceLoad
    {
    public:

        // called before all resource loads.
        // allows the Request to be manipulated or an alternate response to be provided
        void HandleBeforeResourceLoad(IWebBrowser^ browserControl, IRequestResponse^ requestResponse);
    };
}