#include "Label.h"

Label::Label(int width) {
    this->height = 1;
    this->width = width;
    this->showed = true;
}

void Label::draw(Graphics g, int x, int y, size_t z) {
    graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);
	graphics.write(x, y, this->GetValue());
	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);
}
