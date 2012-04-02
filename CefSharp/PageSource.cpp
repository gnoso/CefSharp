#include "stdafx.h"
#include "include/cef_runnable.h"
#include "PageSource.h"

namespace CefSharp
{
   void PageSource::UIT_GetPageSource(CefRefPtr<CefBrowser> browser)
   {
       CefRefPtr<CefV8Context> context = browser->GetMainFrame()->GetV8Context();

		_result = toClr(browser->GetMainFrame()->GetSource());

       SetEvent(_event);
   }

   gcroot<String^> PageSource::GetPageSource(CefRefPtr<CefBrowser> browser)
   {
       AutoLock lock_scope(this);
       _result = nullptr;

       if (CefCurrentlyOn(TID_UI))
       {
           UIT_GetPageSource(browser);
       }
       else
       {
           CefPostTask(TID_UI, NewCefRunnableMethod(this, &PageSource::UIT_GetPageSource, browser));

			TimeSpan timeout = TimeSpan::MaxValue;
			switch (WaitForSingleObject(_event, timeout.Milliseconds))
           {
           case WAIT_TIMEOUT:
           case WAIT_ABANDONED:
           case WAIT_FAILED:
               throw gcnew Exception("Script error");
           }
       }

       return _result;
   }
}
