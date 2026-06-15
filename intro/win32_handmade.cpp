#include <windows.h>

struct projectile
{
    char unsigned IsThisOnFire;
    int Damage;
    int ParticlesPerSecond;
    short HowManyCooks;
};

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd
)
{
    int x = 0xA;
    OutputDebugStringA("This is my output");
    x = x << 4;
}
