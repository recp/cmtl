# Apple's Metal for `C`

<span class="badge-patreon"><a href="https://www.patreon.com/recp" title="Donate to this project using Patreon"><img src="https://img.shields.io/badge/patreon-donate-yellow.svg" alt="Patreon donate button" /></a></span>

C Wrapper for Apple's METAL framework. This library is C bindings of Metal API (MetalGL). Since **OpenGL** is deprecated, this library may build OpenGL api on this library. This could save old games and apps on macOS platform.

Also since this is C bindings for Metal API, it also can help other languages to use Metal with this library. 

Currently this library does not alloc memory for its types. It retains ObjC objects and work on them. This also makes the library very very thin layer on ObjC. 

This is NOT generic rendering library. If you need to that, check this one: [Graphics Kernel](https://github.com/recp/gk), it is also written in C and provides common rendering techniques. It will be cross platform. Since [Graphics Kernel](https://github.com/recp/gk) needs to run on macOS, this library will be macOS backend for that purpose.

Consider to support me on Patreon so I can spend more time on this and related stuffs.

Here sample usage:

```C

MtDevice                   *device;
MtCommandQueue             *cmdQueue;
MtRenderPipelineDescriptor *pipDesc;
MtLibrary                  *lib;
MtFunction                 *vertFunc, *fragFunc;
MtRenderPipelineState      *pip;

device   = mtDeviceCreat();
lib      = mtDefaultLib(device);
cmdQueue = mtCmdQueue(device);
pipDesc  = mtPipelineDescCreat(MtPixelFormatBGRA8Unorm);

vertFunc = mtFuncByName(lib, "vert");
fragFunc = mtFuncByName(lib, "frag");

mtPipelineSetFunc(pipDesc, vertFunc, MT_FUNC_VERT);
mtPipelineSetFunc(pipDesc, fragFunc, MT_FUNC_FRAG);

pip = mtPiplineStateCreat(device, pipDesc);
  
```