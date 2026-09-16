/*

General Flow:

1. GLFW
   ↓
Create window + OpenGL context

2. GLAD
   ↓
Load OpenGL function addresses from the current context/driver

3. OpenGL (the function implementations are stored in drivers that you download,
think about how when you have a PC you always had to update drivers for Nvidia GPUs,
those updates are how implementation bugs get fixed)
   ↓
Use those functions to actually render

*/

/*

Questions to keep in mind while learning OpenGL:

OpenGL: What graphics operations can I request, and what do they mean?

GLFW: How do I get a window/context and interact with the operating system?

GLAD: How does my program get access to the OpenGL functions provided by the driver?

*/


/*

What is the purpose of GLFW:

GLFW → Library
Provides utilities for creating windows, creating/managing the OpenGL context, handling input, etc.

Creating a window isn't really the job of a graphics API.

OpenGL is concerned with things like:

"Draw these triangles."

GLFW is concerned with:

"Give me a window in which I can display those triangles."

It also handles things such as creating an OpenGL context, keyboard input,
mouse input, window sizing, etc. 

*/

/*

What is the purpose of GLAD:

GLAD → OpenGL function loader

GLAD helps your C++ program access the OpenGL functions provided by the driver

This becomes especially important because OpenGL functions aren't necessarily
all directly available to your program as normal statically linked C++ functions.

Your program needs to obtain the addresses of the functions from the OpenGL implementation.
Without a loader like GLAD, you'd have to deal with the platform-specific mechanism for asking:

"Hey operating system/driver, where is the function that implements glDrawArrays?"

GLAD handles that machinery for you.

Thus you don't have to think about:
"Where is this function located? How do I obtain its address?
 Is this different on macOS vs Windows? What OpenGL version does the driver expose?"

 One subtle point: GLAD itself doesn't know how to magically find the functions without help from the platform.
That's why you usually see it initialized after creating an OpenGL context with GLFW. GLFW establishes the context,
and then GLAD can load the functions associated with that context.

*/



All OpenGL objects (e.g. shaders) are accessed by references, values 


Binding in OpenGL means we make any certain object our "current" object, similar to a context
Thus whenever we use a function that modifies that specific type of object, it will modify that
particular "current" object.

