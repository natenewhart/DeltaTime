# DeltaTime

A minimal, header-only C++ frame timing utility built on `<chrono>`. Drop in one file and get accurate delta time with no dependencies beyond the standard library.

## Installation

Copy `DeltaTime.hpp` into your project and include it:

```cpp
#include "DeltaTime.hpp"
```

No build step required.

## Usage

```cpp
DeltaTimer timer;

// Game loop
while (running)
{
    float  dt = timer.GetTimeFloat();  // seconds as float
    double dt = timer.GetTimeDouble(); // seconds as double

    position += velocity * dt;
}
```

### Construction

```cpp
DeltaTimer timer; // Timer starts immediately on construction
```

The internal timestamp is set to the current time on construction, so the first call to `GetTimeFloat()` or `GetTimeDouble()` returns the time elapsed since the object was created.

### Getting Elapsed Time

```cpp
float  dt = timer.GetTimeFloat();  // Returns seconds elapsed as float
double dt = timer.GetTimeDouble(); // Returns seconds elapsed as double
```

Each call updates the internal timestamp, so the next call measures from that point forward. Call once per frame at the top of your game loop.

## Requirements

- C++11 or later
- Standard library `<chrono>`

## License

MIT — see [LICENSE](LICENSE)
