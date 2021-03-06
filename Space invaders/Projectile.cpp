#include "Projectile.h"
#include "Renderer.h"
#include <algorithm>

Projectile::Projectile(float posX, float posY, const std::shared_ptr<Renderer>& renderer, int r, int g, int b)
    :
    m_rect({ posX,posY }, r, g, b, 255, 2, 15, renderer)
{
}

void Projectile::Move(float speed) {
    int oldY = m_rect.GetPoint().y;
    Point2D newLoc = m_rect.GetPoint();
    newLoc.y -= 0.40f * speed;

    m_rect.SetPoint(newLoc);
}

void Projectile::Draw() {
    m_rect.render(RenderFlag::Fill);
}

//Sets the projectiles point with the provided X pos and the default y pos 750
void Projectile::SetXPos(float pos) noexcept {
    m_rect.SetPoint({pos, 750});
}

void Projectile::SetPos(float xPos, float yPos) noexcept {
    m_rect.SetPoint({ xPos, yPos });
}
