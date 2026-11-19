
# Discovery report

## Problem statement

An animation studio needs a reliable, maintainable, and extensible rendering engine that can produce high-quality images while remaining easy to test, understand, and improve over time.


## Client interview summary


1. Reliability and Debugging

Need: The rendering engine must be reliable and easy to debug.

Q (a classmate): "What technical problems have you experienced with your current rendering software?"

A: During the previous project, black artifacts appeared in rendered images. The team spent six months without understanding the cause.

My conclusion: The new engine should include effective debugging tools, logging, and automated tests to help identify rendering errors.


2. Delivery Deadline

Need: The software must be production-ready by January 15.

Q (a classmate): "When does the software need to be ready for production?"

A: The software must be delivered and operational in production by January 15.

My conclusion: We need to prioritize essential features and plan development, testing, and deployment around this deadline.


3. Maintainability

Need: The studio must be able to maintain the software internally.

Q(a classmate): "Who will be responsible for maintaining the rendering software?"

A: The studio wants to maintain the solution in-house.

My conclusion: The codebase should be understandable, well-documented, modular, and supported by automated tests.


4. Image Resolution and Quality

Need: The engine must produce high-quality images in HD format.

Q(a classmate): "What resolution do you use, and how important is image quality?"

A: The studio uses HD format, and high-quality final images are essential.

My conclusion: Image quality should be a major priority. We should clarify the exact resolution and define measurable image quality criteria.


5. Technology Constraints

Need: The studio does not impose specific external tools.

Q(a classmate): "Are there any specific tools or technologies we are required to use?"

A: No specific tools are required.

My conclusion: We have flexibility in choosing development tools and libraries, provided they meet the project's technical and licensing requirements.



## State of the Art

| Solution | Maker | License | Pricing (checked Nov. 16, 2026) | Capabilities | Sources |
|---|---|---|---|---|---|
| Blender Cycles | Blender Foundation and contributors | Apache 2.0 (standalone engine) | Free | CPU/GPU rendering, path tracing, realistic materials, lighting and shadows | [Cycles](https://github.com/blender/cycles), [Blender](https://www.blender.org/) |
| PBRT-v4 | Matt Pharr, Wenzel Jakob, Greg Humphreys and contributors | Apache 2.0 | Free | Physically based rendering, spectral rendering, CPU/GPU support, realistic light simulation | [PBRT](https://www.pbrt.org/), [GitHub](https://github.com/mmp/pbrt-v4) |
| LuxCoreRender | LuxCoreRender open-source community | Apache 2.0 | Free | Physically based rendering, CPU/GPU support, realistic materials, advanced lighting effects | [LuxCoreRender](https://luxcorerender.org/) |


### Analysis and Conclusions

The three solutions demonstrate that high-quality rendering can be achieved using open-source software without expensive proprietary licenses.

Blender Cycles provides a production-oriented rendering engine, PBRT offers a well-documented C++ implementation, and LuxCoreRender focuses on physically based light simulation.

These solutions provide useful references for our project, particularly regarding maintainability, extensibility, and rendering performance.

However, further investigation is needed to determine whether an existing engine could meet the studio's requirements or whether developing a new solution would be more appropriate.




## What is Ray Tracing?

Ray tracing is a rendering technique used to generate 2D images from a 3D scene by simulating how light interacts with objects.

The input is a virtual scene containing objects, materials, light sources, and a camera. For each pixel, the engine sends a ray from the camera into the scene and checks whether it intersects an object. If an intersection is found, the engine calculates the pixel's color based on the object's material and lighting conditions. Additional rays can be used to simulate shadows, reflections, and refractions.

The output is a 2D image composed of the calculated pixel colors. Ray tracing can produce highly realistic images, but it requires significant computing resources, especially for complex scenes and high resolutions.

**Sources:**
- [NVIDIA — Ray Tracing](https://developer.nvidia.com/discover/ray-tracing)
- [Physically Based Rendering — Introduction](https://pbr-book.org/4ed/Introduction)
- [PBRT — Photorealistic Rendering and the Ray-Tracing Algorithm](https://pbr-book.org/4ed/Introduction/Photorealistic_Rendering_and_the_Ray-Tracing_Algorithm)



## What is C++?

C++ is a compiled, general-purpose programming language known for its performance, flexibility, and control over system resources. It is widely used in applications requiring intensive computations, such as graphics engines, game engines, and rendering software.

### Programming Paradigms

C++ supports multiple programming paradigms:

- **Procedural programming:** Organizing code into functions and procedures to perform specific tasks.
- **Object-oriented programming (OOP):** Using classes, encapsulation, inheritance, and polymorphism to organize and extend software.
- **Generic programming:** Using templates to create reusable algorithms and data structures.
- **Functional programming:** Using functions, lambdas, and immutable data where appropriate.

Compared to Java, C++ offers more direct control over memory management. Unlike Python, C++ is typically compiled into native machine code, making it suitable for computationally intensive applications.

### What to Watch Out For

C++ provides significant flexibility but also introduces several challenges:

- **Memory management:** Incorrect resource handling can lead to memory leaks.
- **Pointers and references:** Invalid pointers or references can cause crashes or undefined behavior.
- **Undefined behavior:** Operations such as accessing arrays outside their bounds may lead to unpredictable results.
- **Resource management:** RAII and smart pointers help manage resources safely.
- **Performance:** Unnecessary copies and inefficient algorithms can significantly affect rendering time.

For this project, following modern C++ practices and writing automated tests will be important to ensure reliability and maintainability.

### Shaping the Domain Model

C++ classes and structures can represent the main concepts of a ray tracing engine:

- `Ray`: Represents a ray with an origin and a direction.
- `Camera`: Generates rays corresponding to image pixels.
- `Sphere`: Represents a geometric object and calculates ray intersections.
- `Material`: Defines how an object interacts with light.
- `Light`: Represents a source of illumination.
- `Scene`: Contains the objects, lights, and camera.
- `Renderer`: Computes pixel colors and generates the final image.

Object-oriented programming can help separate these responsibilities, making the engine easier to understand, test, and extend. Mathematical operations can be implemented using reusable functions and data structures.

This is an initial conceptual model, not a finalized software architecture.

### Current pixel-to-image model

The ray tracer now computes every pixel for one sphere and can save the image
as a PNG:

| Class | Holds | Operations | State and deferred behavior |
|---|---|---|---|
| `Vector` | x, y, z | Addition, subtraction, scaling, dot product, length, normalization | Implemented in `math/`. |
| `Colour` | Red, green, blue channels | Read the r, g, and b components | A separate type held by `Sphere` and by each `Image` pixel; see [ADR 0007](../adr/0007-colour-as-a-separate-type.md). |
| `Ray` | Origin and direction vectors | Read origin and direction | Implemented; evaluating a point at t is deferred until needed. |
| `Sphere` | Centre, radius, and colour | Test whether a ray hits it; return its colour | Implemented; choosing the nearest hit is deferred until there are multiple spheres. |
| `Camera` | Eye, screen-centre vectors, and screen width | Create a ray through a pixel; render a sphere into an image | Image resolution is chosen by the caller; only one sphere is rendered. |
| `Image` | Width, height, and a colour per pixel | Read and set a pixel | Stores pixels privately in row-major order; knows nothing about file formats. |
| `ImageSaver` | No state | Save a whole image to a path or throw `std::runtime_error` | Abstract output contract. |
| `PngSaver` | No state | Save an image as PNG | Uses LodePNG behind `ImageSaver`; channel values are rounded to bytes; see [ADR 0008](../adr/0008-png-output-with-lodepng.md). |

World coordinates use x-right, y-up, z-forward, while image columns and rows
are counted from the top left; see the proposed
[coordinate-system ADR](../adr/0009-coordinate-system.md).

For now, `trace(ray, sphere)` decides the pixel colour: it returns the
sphere's colour on a hit and black otherwise. This is a one-sphere spike; the
decision can grow when the scene contains more objects or a background.

**Sources:**
- [ISO C++ — C++ FAQ](https://isocpp.org/wiki/faq/big-picture)
- [cppreference — C++ Language](https://en.cppreference.com/w/cpp/language)
- [cppreference — RAII](https://en.cppreference.com/w/cpp/language/raii)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)