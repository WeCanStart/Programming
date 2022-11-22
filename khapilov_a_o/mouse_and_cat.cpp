#include <iostream>
#include <cmath>

double max(double lhs, double rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

struct RDec2d {
    double x = 0;
    double y = 0;
};


double len(RDec2d tmp) {
    return std::sqrt(tmp.x * tmp.x + tmp.y * tmp.y);
}

RDec2d norm(RDec2d tmp) {
    tmp.x /= len(tmp);
    tmp.y /= len(tmp);
    return tmp;
}

double angle(RDec2d tmp) {
    return std::atan2(tmp.y, tmp.x);
}

RDec2d operator+ (RDec2d const lhs, RDec2d const rhs) {
    RDec2d tmp(lhs);
    tmp.x += rhs.x;
    tmp.y += rhs.y;
    return tmp;
}

RDec2d operator* (RDec2d const lhs, double const rhs) {
    RDec2d tmp(lhs);
    tmp.x *= rhs;
    tmp.y *= rhs;
    return tmp;
}

RDec2d operator- (RDec2d const lhs, RDec2d const rhs) {
    RDec2d tmp(lhs);
    tmp.x -= rhs.x;
    tmp.y -= rhs.y;
    return tmp;
}

void operator+= (RDec2d& const lhs, RDec2d const rhs) {
    RDec2d tmp(lhs);
    lhs.x += rhs.x;
    lhs.y += rhs.y;
}

void operator-= (RDec2d& const lhs, RDec2d const rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
}

double dot(RDec2d lhs, RDec2d rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}
double cos_between(RDec2d lhs, RDec2d rhs) {
    return std::abs(dot(lhs, rhs)) / (len(lhs) * len(rhs));
}

struct RPol2d {
    double r = 0;
    double phi = 0;
};


RPol2d Rec_to_Pol(RDec2d vec) {
    RPol2d ans(len(vec), angle(vec));
    return ans;
}

RDec2d Rec_to_Pol(RPol2d vec) {
    RDec2d ans(vec.r * std::cos(vec.phi), vec.r * std::sin(vec.phi));
    return ans;
}


int main() {
    RDec2d r_mouse, r_cat;
    std::cin >> r_mouse.x >> r_mouse.y >> r_cat.x >> r_cat.y;
    RDec2d v_mouse;
    std::cin >> v_mouse.x >> v_mouse.y;
    double v_full_cat = 0;
    std::cin >> v_full_cat;
    RDec2d vec_cat_to_mouse = r_mouse - r_cat;
    RDec2d v_cat = norm(vec_cat_to_mouse) * v_full_cat;
    double c_c;
    std::cin >> c_c;

    bool eaten = false;
    bool hidden = false;
    if (max(len(v_mouse), v_full_cat) < std::numeric_limits<double>::epsilon()) {
        std::cout << "That can continuous infinitly";
        return 0;
    }
    double dist_before = 0;
    double dist_now = len(vec_cat_to_mouse);
    double dt = 0.01 / (max(len(v_mouse), v_full_cat) * (1 + 9 / exp(dist_now)));
    double t = 0;
    while (!eaten && !hidden) {
        r_mouse += v_mouse * dt;
        r_cat += v_cat * dt;
        vec_cat_to_mouse = r_mouse - r_cat;
        v_cat = norm(vec_cat_to_mouse) * v_full_cat;
        dist_now = len(vec_cat_to_mouse);
        if (dist_now <= c_c) {
            eaten = true;
        }
        std::cout << r_mouse.y << ' ';
        if (r_mouse.y <= 0) {
            hidden = true;
        }
        dt = 0.01 / (max(len(v_mouse), v_full_cat) * (1 + 9 / exp(dist_now)));
        t += dt;
    }
    if (eaten && hidden) {
        std::cout << "Decreas base dt, please";
        return 0;
    }
    if (eaten) {
        std::cout << "Mouse was eaten in " << t << " seconds";
    }
    if (hidden) {
        std::cout << "Mouse hidden in " << t << " seconds";
    }
    return 0;
}