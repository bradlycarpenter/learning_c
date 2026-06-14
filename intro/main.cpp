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
    projectile Test;

    int SizeOfTest = sizeof(Test);

    Test.IsThisOnFire = 1;
    Test.Damage = 2;
    Test.ParticlesPerSecond = 3;
    Test.HowManyCooks = 4;

    projectile* ProjectilePointer = &Test;
    short* MrPointerMan = (short*)&Test;
}
