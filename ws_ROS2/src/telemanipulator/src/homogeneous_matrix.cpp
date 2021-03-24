#include "../include/homogeneous_matrix.h"

#include <math.h> /* sin, cos, abs */

#include <array>
#include <cassert>  // assert
#include <cmath>    // std::abs
#include <iostream>
#include <limits>  // std::numeric_limits, std::epsilon
#include <ostream>

RotationMatrix::RotationMatrix() {
  m_matrix[0] = {1.0, 0.0, 0.0};
  m_matrix[1] = {0.0, 1.0, 0.0};
  m_matrix[2] = {0.0, 0.0, 1.0};
}

RotationMatrix::RotationMatrix(const std::array<float, 3> &row_1, const std::array<float, 3> &row_2, const std::array<float, 3> &row_3) {
  m_matrix[0] = row_1;
  m_matrix[1] = row_2;
  m_matrix[2] = row_3;
}

std::array<float, 3> &RotationMatrix::operator[](const int index) {
  if (index >= 3) {
    std::cout << "Array index out of bound, exiting." << std::endl;
    exit(0);
  }
  return m_matrix[index];
}

std::array<float, 3> RotationMatrix::operator[](const int index) const {
  if (index >= 3) {
    std::cout << "Array index out of bound, exiting." << std::endl;
    exit(0);
  }
  return m_matrix[index];
}

RotationMatrix RotationMatrix::operator*(const RotationMatrix &other) const {
  RotationMatrix result;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      float res_ij = 0.;

      for (int k = 0; k < 3; k++) {
        res_ij += m_matrix[i][k] * other.m_matrix[k][j];
      }

      result.m_matrix[i][j] = res_ij;
    }
  }
  return result;
}

void RotationMatrix::print() const {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << m_matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool RotationMatrix::isValid() const {
  float aei = m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2];
  float bfg = m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0];
  float cdh = m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1];
  float ceg = m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0];
  float bdi = m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2];
  float afh = m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1];

  /* Rule of Sarrus */
  float determinant = aei + bfg + cdh - ceg - bdi - afh;
  return (std::abs(determinant - 1) < std::numeric_limits<float>::epsilon()) ? true : false;
}

/* Copied from GLM. Switched colom major to row major and placed the real part of the quaternion at the end. */
std::array<float, 4> RotationMatrix::toQuat() const {
  float fourXSquaredMinus1 = m_matrix[0][0] - m_matrix[1][1] - m_matrix[2][2];
  float fourYSquaredMinus1 = m_matrix[1][1] - m_matrix[0][0] - m_matrix[2][2];
  float fourZSquaredMinus1 = m_matrix[2][2] - m_matrix[0][0] - m_matrix[1][1];
  float fourWSquaredMinus1 = m_matrix[0][0] + m_matrix[1][1] + m_matrix[2][2];

  int biggestIndex = 0;

  float fourBiggestSquaredMinus1 = fourWSquaredMinus1;
  if (fourXSquaredMinus1 > fourBiggestSquaredMinus1) {
    fourBiggestSquaredMinus1 = fourXSquaredMinus1;
    biggestIndex             = 1;
  }
  if (fourYSquaredMinus1 > fourBiggestSquaredMinus1) {
    fourBiggestSquaredMinus1 = fourYSquaredMinus1;
    biggestIndex             = 2;
  }
  if (fourZSquaredMinus1 > fourBiggestSquaredMinus1) {
    fourBiggestSquaredMinus1 = fourZSquaredMinus1;
    biggestIndex             = 3;
  }

  float biggestVal = sqrt(fourBiggestSquaredMinus1 + 1.) * 0.5;
  float mult       = 0.25 / biggestVal;

  switch (biggestIndex) {
    case 0:
      return {(m_matrix[2][1] - m_matrix[1][2]) * mult, (m_matrix[0][2] - m_matrix[2][0]) * mult, (m_matrix[1][0] - m_matrix[0][1]) * mult, biggestVal};
    case 1:
      return {biggestVal, (m_matrix[1][0] + m_matrix[0][1]) * mult, (m_matrix[0][2] + m_matrix[2][0]) * mult, (m_matrix[2][1] - m_matrix[1][2]) * mult};
    case 2:
      return {(m_matrix[1][0] + m_matrix[0][1]) * mult, biggestVal, (m_matrix[2][1] + m_matrix[1][2]) * mult, (m_matrix[0][2] - m_matrix[2][0]) * mult};
    case 3:
      return {(m_matrix[0][2] + m_matrix[2][0]) * mult, (m_matrix[2][1] + m_matrix[1][2]) * mult, biggestVal, (m_matrix[1][0] - m_matrix[0][1]) * mult};
    default:  // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
      assert(false);
      return {0., 0., 0., 1.};
  }
}

/* Constructors */
HomogeneousMatrix::HomogeneousMatrix(const RotationMatrix &rotation_matrix, const std::array<float, 3> &translation_vector)
    : m_rotation_matrix(rotation_matrix), m_translation_vector(translation_vector) {}

HomogeneousMatrix::HomogeneousMatrix() {
  m_rotation_matrix    = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
  m_translation_vector = {0.0, 0.0, 0.0};
}

HomogeneousMatrix::HomogeneousMatrix(const std::array<float, 3> &rotation_angles,
                                     const std::array<float, 3> &translation_vector,
                                     const bool is_degree) {
  m_rotation_matrix       = eulerAngleXYZ(rotation_angles[0], rotation_angles[1], rotation_angles[2], is_degree);
  m_translation_vector[0] = translation_vector[0];
  m_translation_vector[1] = translation_vector[1];
  m_translation_vector[2] = translation_vector[2];
}

/* Euler Angle Matrix */

RotationMatrix HomogeneousMatrix::eulerAngleXYZ(const float rotation_x, const float rotation_y, const float rotation_z, const bool is_degree) const {
  float c1;
  float c2;
  float c3;
  float s1;
  float s2;
  float s3;

  if (is_degree) {
    c1 = cos(-rotation_x * 0.01745329251994329576923690768489);
    c2 = cos(-rotation_y * 0.01745329251994329576923690768489);
    c3 = cos(-rotation_z * 0.01745329251994329576923690768489);
    s1 = sin(-rotation_x * 0.01745329251994329576923690768489);
    s2 = sin(-rotation_y * 0.01745329251994329576923690768489);
    s3 = sin(-rotation_z * 0.01745329251994329576923690768489);
  }

  else {
    c1 = cos(-rotation_x);
    c2 = cos(-rotation_y);
    c3 = cos(-rotation_z);
    s1 = sin(-rotation_x);
    s2 = sin(-rotation_y);
    s3 = sin(-rotation_z);
  }

  RotationMatrix result;
  result[0][0] = c2 * c3;
  result[1][0] = -c1 * s3 + s1 * s2 * c3;
  result[2][0] = s1 * s3 + c1 * s2 * c3;
  result[0][1] = c2 * s3;
  result[1][1] = c1 * c3 + s1 * s2 * s3;
  result[2][1] = -s1 * c3 + c1 * s2 * s3;
  result[0][2] = -s2;
  result[1][2] = s1 * c2;
  result[2][2] = c1 * c2;
  return result;
}

/* Rotations */

void HomogeneousMatrix::rotate(const float rotation_x, const float rotation_y, const float rotation_z, const bool is_degree) {
  RotationMatrix rotation_matrix = eulerAngleXYZ(rotation_x, rotation_y, rotation_z, is_degree);

  m_rotation_matrix = m_rotation_matrix * rotation_matrix;
}

void HomogeneousMatrix::rotate(const std::array<float, 3> &rotation_angles, const bool is_degree) {
  RotationMatrix rotation_matrix = eulerAngleXYZ(rotation_angles[0], rotation_angles[1], rotation_angles[2], is_degree);

  m_rotation_matrix = m_rotation_matrix * rotation_matrix;
}

/* Translations */

void HomogeneousMatrix::translate(const float x, const float y, const float z) {
  m_translation_vector[0] = m_translation_vector[0] + x;
  m_translation_vector[1] = m_translation_vector[1] + y;
  m_translation_vector[2] = m_translation_vector[2] + z;
}

void HomogeneousMatrix::translate(const std::array<float, 3> &translation_vector) {
  m_translation_vector[0] = m_translation_vector[0] + translation_vector[0];
  m_translation_vector[1] = m_translation_vector[1] + translation_vector[1];
  m_translation_vector[2] = m_translation_vector[2] + translation_vector[2];
}

/* Print */

void HomogeneousMatrix::print() const {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << m_rotation_matrix[i][j] << " ";
    }
    std::cout << m_translation_vector[i];
    std::cout << std::endl;
  }
}

/* Reset */

void HomogeneousMatrix::resetToIdentity() {
  m_rotation_matrix    = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
  m_translation_vector = {0.0, 0.0, 0.0};
}

/* Sanity Check */

bool HomogeneousMatrix::rotationMatrixIsValid() const {
  return m_rotation_matrix.isValid();
}

/* Getter */

RotationMatrix HomogeneousMatrix::getRotationMatrix() const { return m_rotation_matrix; }
std::array<float, 3> HomogeneousMatrix::getTranslationVector() const { return m_translation_vector; }

std::array<float, 7> HomogeneousMatrix::toPoseArray() const {
  std::array<float, 4> quaternion = m_rotation_matrix.toQuat();

  std::array<float, 7> result;

  for (int i = 0; i < 3; i++) {
    result[i] = m_translation_vector[i];
  }

  for (int i = 3; i < 7; i++) {
    result[i] = quaternion[i - 3];
  }

  return result;
}

/* Multiplication */

HomogeneousMatrix HomogeneousMatrix::operator*(const HomogeneousMatrix &b) const {
  HomogeneousMatrix result;
  std::array<float, 3> translation;

  for (int i = 0; i < 3; i++) {
    float dot = 0.;
    for (int j = 0; j < 3; j++) {
      dot += m_rotation_matrix[i][j] * b.m_translation_vector[j];

      float res_ij = 0.;
      for (int k = 0; k < 3; k++) {
        res_ij += m_rotation_matrix[i][k] * b.m_rotation_matrix[k][j];
      }

      result.m_rotation_matrix[i][j] = res_ij;
    }
    dot += m_translation_vector[i];
    translation[i] = dot;
  }

  result.m_translation_vector = translation;

  return result;
}
