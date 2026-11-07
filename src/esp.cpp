#include <windows.h>
#include <vector>

#include "esp.h"
#include "overlay.h"

void ESP::Draw(const Player& p, const Vec2& screen, float distance) {
    if (!Config::esp_enabled) return;

    Color color = p.visible ? Config::visible_color : Config::hidden_color;
    float height = 2200.0f / distance;
    float width = height / 2.0f;

    if (Config::box) {
        Overlay::Rect(screen.x - width / 2, screen.y - height, width, height, color);
    }
    if (Config::skeleton) {
        Overlay::Skeleton(p.bones, color);
    }
    if (Config::health) {
        Overlay::Bar(screen.x - width / 2 - 6, screen.y - height, 4, height,
                     p.health, Color::Green);
    }
    if (Config::distance) {
        Overlay::Text(screen.x, screen.y + 4, std::to_string((int)distance) + "m", color);
    }
}
