#include "chunk.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <assert.h>

// allocate memory for block. initialize all with air blocks
void initialize_voxel_chunk(VoxelChunkData *data){
  size_t voxel_chunk_count = CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE;
  size_t voxel_chunk_mem_size = voxel_chunk_count * sizeof(VoxelBlock);
  VoxelBlock *blocks = malloc(voxel_chunk_mem_size);
  data-> chunk_size = CHUNK_SIZE;
  data->allocated_size = voxel_chunk_mem_size;
  data->blocks = blocks;

  for(size_t i = 0; i < voxel_chunk_count; i++){
    VoxelBlock block = {
      .block_type = BLOCK_AIR,
      .data = NULL,
      .data_size = 0,
    };
    blocks[i] = block;
  }

}

void destroy_voxel_chunk(VoxelChunkData *data){
  free(data->blocks);
}

void generate_voxel_terrain(VoxelChunkData *data, 
                            uint32_t seed, 
                            struct VoxelGenerationConfig config){
  printf("Seed is ignored, should be zero: %d\n", seed);
  assert(seed == 0);
  puts("generate_voxel_terrain should do nothing");
   assert(!(config.flatland && config.amplified && config.random));
  for(size_t x = 0; x < data->chunk_size;x++){
    for(size_t y = 0; y < data->chunk_size; y++){
      for(size_t z = 0; z < data->chunk_size; z++){
        printf("Placing Block at(x: %ld, y: %ld, z: %ld)\n", x, y, z);
      }
    }
  }
}

void generate_voxel_mesh(VoxelChunkData *data, VoxelMesh *mesh_result){
  // write base case where no vertices are generated
  
}
