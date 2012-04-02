#include "stdafx.h"
#pragma once

namespace CefSharp
{
   public class PageSource
   {
   private:
       HANDLE _event;

       gcroot<String^> _result;

       void UIT_GetPageSource(CefRefPtr<CefBrowser> browser);

   public:
       PageSource()
       {
           _event = CreateEvent(NULL, FALSE, FALSE, NULL);
       }

		DECL gcroot<String^> GetPageSource(CefRefPtr<CefBrowser> browser);

       IMPLEMENT_LOCKING(PageSource);
       IMPLEMENT_REFCOUNTING(PageSource);
   };
}
