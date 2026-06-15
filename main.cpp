#include <windows.h>

LRESULT CALLBACK
MainWindowCallback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
  LRESULT Result = 0;
  switch (Message)
  {
  case WM_SIZE:
  {
    OutputDebugStringA("WM_SIZE\n");
  }
  break;

  case WM_DESTROY:
  {
    OutputDebugStringA("WM_DESTROY\n");
  }
  break;

  case WM_CLOSE:
  {
    OutputDebugStringA("WM_CLOSE\n");
  }
  break;

  case WM_PAINT:
  {
    PAINTSTRUCT Paint;

    HDC DeviceContext = BeginPaint(Window, &Paint);

    int  X      = Paint.rcPaint.left;
    int  Y      = Paint.rcPaint.top;
    LONG Height = Paint.rcPaint.bottom - Paint.rcPaint.top;
    LONG Width  = Paint.rcPaint.right - Paint.rcPaint.left;

    PatBlt(DeviceContext, X, Y, Width, Height, WHITENESS);
    EndPaint(Window, &Paint);
  }
  break;

  default:
  {
    // OutputDebugStringA("DEFAULT\n");
    Result = DefWindowProc(Window, Message, WParam, LParam);
  }
  break;
  }
  return (Result);
}

int CALLBACK WinMain(
    HINSTANCE Instance, HINSTANCE PrevInstance, LPSTR CommandLine, int ShowCode)
{
  WNDCLASS WindowClass = {};

  // TODO Read up on these on MDN:
  // https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassw

  WindowClass.style         = CS_OWNDC;
  WindowClass.lpfnWndProc   = MainWindowCallback;
  WindowClass.hInstance     = Instance;
  WindowClass.lpszClassName = "HandMadeHeroWindowClass";

  if (RegisterClass(&WindowClass))
  {
    HWND WindowHandle = CreateWindowEx(
        0,
        WindowClass.lpszClassName,
        "HandMadeHero",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        0,
        0,
        Instance,
        0);
    if (WindowHandle)
    {
      MSG Message;
      for (;;)
      {
        BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
        if (MessageResult > 0)
        {
          TranslateMessage(&Message);
          DispatchMessage(&Message);
        }
        else
        {
          break;
        }
      }
    }
    else
    {
      // TODO: Error Logging
      OutputDebugString("Error Creating Window EX");
    }
  }
  else
  {
    // TODO: Error Logging
    OutputDebugString("Error Registring Window Class");
  }
}
