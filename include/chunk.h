#ifndef CHUNK_H
#define CHUNK_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CHUNK_SIZE 16

typedef enum {
  BLOCK_AIR=0,
  BLOCK_STONE,
} BlockType;

typedef struct {
  BlockType block_type;
  // this should be null by default
  void *data;
  size_t data_size;
} VoxelBlock;

// While this struct is under development, if the flatland option is set to
// false then error will occur.
struct VoxelGenerationConfig {
  bool flatland;
  bool amplified;
  bool random;
};
typedef struct {
  // Voxel Chunk should be chunk_size^3
  uint32_t chunk_size;
  // size in bytes of *blocks pointer
  size_t allocated_size;
  VoxelBlock *blocks;
} VoxelChunkData;

typedef struct {
  uint32_t vbo;
  int vertex_count;
  uint32_t ebo;
  int index_count;
} VoxelMesh;

// ready a chunk struct to be usabled, allocate memory iin gpu
void initialize_voxel_chunk(VoxelChunkData *data);

// destroy
void destroy_voxel_chunk(VoxelChunkData *data);

// memcpy
void deep_copy_voxel_chunk(VoxelChunkData *data);

// shallow copy is simply an assigning to a new struct in stack memory
void shallow_copy_voxel_chunk(VoxelChunkData *data);

// by default should generate a flatworld
// TODO: move out of file, generation.h
void generate_voxel_terrain(VoxelChunkData *data, uint32_t seed, struct VoxelGenerationConfig config);

void generate_voxel_mesh(VoxelChunkData *data, VoxelMesh *mesh_result);
void voxel_mesh_destroy(VoxelMesh *mesh);

static const float VOXEL_VERTICES[] = {
    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.5f,  -0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  -0.5f, 0.0f,
    0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  0.0f,
    1.0f,  1.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.5f,  -0.5f,
    0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  0.0f,
    0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
    1.0f,  1.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,

    -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  -0.5f, 0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  -0.5f, -0.5f, -0.5f, 0.0f,
    0.0f,  0.0f,  0.0f,  1.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,
    0.0f,  1.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,

    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  -0.5f, -0.5f, 0.0f,
    0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,
    0.0f,  1.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,

    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  -0.5f, 0.5f,  0.0f,
    0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,
    1.0f,  0.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,

    -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  0.5f,  0.5f,  0.0f,
    0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
    1.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f};
const float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
#endif
