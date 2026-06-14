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
    projectile Projectiles[40];
    int SizeOfProjectiles = sizeof(Projectiles);
    projectile* ProjectilePointer = Projectiles;
    int SizeOfProjectilePointer = sizeof(ProjectilePointer);
}
