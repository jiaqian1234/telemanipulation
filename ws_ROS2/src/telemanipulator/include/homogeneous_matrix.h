#pragma once
#include <array>

class RotationMatrix {
 private:
  std::array<std::array<float, 3>, 3> m_matrix;

 public:
  RotationMatrix();
  RotationMatrix(const std::array<float, 3> &row_1, const std::array<float, 3> &row_2, const std::array<float, 3> &row_3);

  std::array<float, 3> &operator[](const int index);

  std::array<float, 3> operator[](const int index) const;

  RotationMatrix operator*(const RotationMatrix &other) const;

  void print() const;

  bool isValid() const;

  std::array<float, 4> toQuat() const;
};

class HomogeneousMatrix {
 private:
  RotationMatrix m_rotation_matrix;
  std::array<float, 3> m_translation_vector;

  // Order of Rotation x -> y -> z (around intrinsic coordinates) results in R_x*R_y*R_z
  RotationMatrix eulerAngleXYZ(const float rotation_x, const float rotation_y, const float rotation_z, const bool is_degree) const;

 public:
  HomogeneousMatrix(const RotationMatrix &rotation_matrix, const std::array<float, 3> &translation_vector);

  // Rotation angles in order x, y, z, Translation vector in order x, y, z
  HomogeneousMatrix(const std::array<float, 3> &rotation_angles, const std::array<float, 3> &translation_vector, const bool is_degree);

  HomogeneousMatrix();

  HomogeneousMatrix operator*(const HomogeneousMatrix &b) const;

  void print() const;

  void resetToIdentity();

  // Order of Rotation x -> y -> z (around intrinsic coordinates) results in R_x*R_y*R_z
  void rotate(const float x, const float y, const float z, const bool is_degree);

  // Order of Rotation x -> y -> z (around intrinsic coordinates) results in R_x*R_y*R_z
  void rotate(const std::array<float, 3> &rotation_angles, const bool is_degree);

  void translate(const std::array<float, 3> &translation_vector);
  void translate(const float x, const float y, const float z);

  RotationMatrix getRotationMatrix() const;
  std::array<float, 3> getTranslationVector() const;
  bool rotationMatrixIsValid() const;

  std::array<float, 7> toPoseArray() const;
  std::array<float, 4> rotationMatrixToQuaternion() const;
};
