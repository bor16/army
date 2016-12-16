#include "Modifier.h"

std::ostream& operator<<(std::ostream& out, const Modifier& modifier) {
    out << modifier.getPoints();
    return out;
}
