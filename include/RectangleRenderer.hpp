#ifndef EXREND2D_RECTANGLE_RENDERER_HPP
#define EXREND2D_RECTANGLE_RENDERER_HPP

#include <array>

#include "Quad.hpp"
#include "Shader.hpp"
#include "Vertex.hpp"

constexpr size_t MaxQuads = 8192;
constexpr size_t MaxVertices = MaxQuads * 4;
constexpr size_t MaxIndices = MaxQuads * 6;
constexpr size_t MaxTextures = 16;

class RectangleRenderer {
  friend class Window;

public:
  RectangleRenderer(Shader &Shader, int WindowWidth, int WindowHeight);

  float createTexture(const std::string &Path);
  float createTextureJPG(const std::string &Path);
  float createTexturePNG(const std::string &Path);

  void addToBatch(const Quad &ToAdd);
  void drawBatch();
  void resetData();

private:
  RectangleRenderer() = default;
  Shader RecShader;

  std::array<unsigned int, MaxTextures> TextureSlots = {};
  unsigned int TextureSlotIndex = 1;
  // if we just want to render a color, we use the white texture
  unsigned int WhiteTexture = 0;
  unsigned int WhiteTextureSlot = 0;

  unsigned int VAO, VBO, EBO;
  Vertex Vertices[MaxVertices] = {};
  unsigned int VerticesIndex = 0, IndicesCounter = 0;
  int WindowWidth = 800;
  int WindowHeight = 600;
};

#endif
