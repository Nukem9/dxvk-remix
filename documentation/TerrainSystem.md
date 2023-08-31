# Terrain System

Terrain is handled by baking original game draw calls into a single material for the terrain. This bakes multiple layers of terrain as the original game composited them into a single material. Then during ray tracing the surfaces associated with terrain textures sample from the shared terrain material rather than from different material layers. Textures that are to be considered as terrain need to be tagged as [rtx.terrainTextures](../RtxOptions.md). The baking is done along a single geometric direction. Namely it bakes material projecting downwards onto a terrain plane and, therefore, only multi-layer surfaces that are horizontal for the most part should be tagged as terrain textures. Some vertical slope is acceptable, though the steeper the slope the larger terrain resolution is needed to reconstruct the full detail of the input textures during ray tracing. The vertical axis in the game is determined via [rtx.zUp](../RtxOptions.md) option and. Terrain baker is resolution is parameterized off

Game authoring steps:
- set [rtx.zUp](../RtxOptions.md)
- set [rtx.sceneScale](../RtxOptions.md)
- tag terrain textures
- adjust Terrain Baker properties to reach desired resolution and performance for the terrain. 

Supported:
- Programmable shaders
- Replacement materials - AlbedoOpacity texture and secondary PBR textures: Normal, Tangent, Roughness, Metallic and Emissive texture

Caveates/limitations:
- Material property constants [rtx.terrainBaker.material.properties.*](../RtxOptions.md) used by Terrain Baker are set for the material used for terrain rendering. These properties are not baked. If a replacement material for any of the input terrain texture layers replaces this constant (i.e. roughness, emissive, etc. ), then the shared constant will not be used. Therefore all materials tagged as terrain need to have this replacement texture type set. In the future this could be handled by baking the constant into a terrain texture if a replacement texture is specified for any of the active terrain meshes.
- Using too high resolution replacement textures can have noticeable performance impact. Adjust [rtx.terrainBaker.material.maxResolutionToUseForReplacementMaterials](../RtxOptions.md) to balance quality vs performance cost of baking replacement textures.

Future considerations / not supported (yet):
- Material constants per input terrain replacement material.
- Better performance for baking high resolution textures
- Orthogonal surfaces (i.e. walls with floor) and separate multi-layer surfaces (i.e. baked road on a bridge over another baked road below). For these cases you can use the decal system. The benefit of the terrain system to the decal system is that the terrain baking exactly replicates original game's blending while the decal system only approximates the original blending. On the other hand, decal system supports blending in any direction and the input decal textures are sampled at the desired resolution at the time of ray hits the surface while the terrain system resamples original textures to a shared terrain texture. This can result in a of loss of image fidelity depending on the parametrization of the terrain system (see [rtx.terrainBaker.*](../RtxOptions.md)).