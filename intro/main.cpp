#include <windows.h>

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd
)
{
  MessageBox(0, "This is handmade hero", "Handmade Hero", MB_OK|MB_ICONINFORMATION);
}
