#include "CBoundingBox.h"

CBoundingBox::CBoundingBox(Vec2 size) : size{size}, halfSize{size.x / 2.F, size.y / 2.F} {}