#pragma once

class Color {
  public:
    Color();
    Color(double red, double green, double blue);
    double red() const;
    double green() const;
    double blue() const;

    void setRed(double red) {
        r = red;
    }

    void setGreen( double green ) {
        g = green;
    }

    void setBlue( double blue ) {
        b = blue;
    }

  private:
    double r{1.0};
    double g{0.0};
    double b{0.0};
};
