#include "Energy.h"

Energy::Energy(int limit) : Health(limit) {}

Energy::Energy(int points, int limit) : Health(points, limit) {}

Energy::~Energy() {}
