#include "../include/pivot_transformation.h"

#include <math.h>

#include <array>
#include <cmath>
#include <iostream>

PivotTransform::PivotTransform(const float pan,
                               const float tilt,
                               const float spin,
                               const float depth,
                               const std::array<float, 3> &pivot_point_position,
                               const std::array<float, 3> &pivot_point_orientation,
                               const bool is_degree)
    : m_pan(pan), m_tilt(tilt), m_spin(spin), m_depth(depth), m_pivot_point_position(pivot_point_position), m_pivot_point_orientation(pivot_point_orientation), m_is_degree(is_degree) {
  updateTransformation();
}

PivotTransform::PivotTransform()
    : m_pan(0), m_tilt(0), m_spin(0), m_depth(0), m_is_degree(false), m_pivot_point_position({0.0, 0.0, 0.0}), m_pivot_point_orientation({0.0, 0.0, 0.0}) {
  m_transformation.resetToIdentity();
}

void PivotTransform::updateTransformation() {
  HomogeneousMatrix trocar_position    = {{0., 0., 0.}, m_pivot_point_position, m_is_degree};
  HomogeneousMatrix trocar_orientation = {m_pivot_point_orientation, {0., 0., 0.}, m_is_degree};
  HomogeneousMatrix tool_rotation      = {{m_tilt, m_pan, m_spin}, {0., 0., 0.}, m_is_degree};
  HomogeneousMatrix tool_translation   = {{0., 0., 0.}, {0., 0., m_depth}, m_is_degree};
  HomogeneousMatrix result;

  m_transformation = trocar_position * trocar_orientation * tool_rotation * tool_translation;
}

void PivotTransform::pan(const float delta_pan) {
  m_pan += delta_pan;
  updateTransformation();
}

void PivotTransform::tilt(const float delta_tilt) {
  m_tilt += delta_tilt;
  updateTransformation();
}

void PivotTransform::spin(const float delta_spin) {
  m_spin += delta_spin;
  updateTransformation();
}

void PivotTransform::insert(const float delta_insert) {
  m_depth += delta_insert;
  updateTransformation();
}

void PivotTransform::updateTransformationRelative(const float delta_pan,
                                                  const float delta_tilt,
                                                  const float delta_spin,
                                                  const float delta_depth) {
  m_pan += delta_pan;
  m_tilt += delta_tilt;
  m_spin += delta_spin;
  m_depth += delta_depth;

  updateTransformation();
}

void PivotTransform::updateTransformationAbsolute(const float new_pan,
                                                  const float new_tilt,
                                                  const float new_spin,
                                                  const float new_depth) {
  m_pan   = new_pan;
  m_tilt  = new_tilt;
  m_spin  = new_spin;
  m_depth = new_depth;

  updateTransformation();
}

void PivotTransform::updateTrocarPoseRelative(const std::array<float, 3> &delta_pivot_point_position,
                                              const std::array<float, 3> &delta_pivot_point_orientation) {
  for (int i = 0; i < 3; i++) {
    m_pivot_point_position[i] += delta_pivot_point_position[i];
    m_pivot_point_orientation[i] += delta_pivot_point_orientation[i];
  }

  updateTransformation();
}

void PivotTransform::updateTrocarPoseAbsolute(const std::array<float, 3> &new_pivot_point_position,
                                              const std::array<float, 3> &new_pivot_point_orientation) {
  m_pivot_point_position    = new_pivot_point_position;
  m_pivot_point_orientation = new_pivot_point_orientation;

  updateTransformation();
}

std::array<float, 4> PivotTransform::getPivotState() const {
  std::array<float, 4> state = {m_pan, m_tilt, m_spin, m_depth};
  return state;
}

std::array<float, 7> PivotTransform::getPivotPose() const {
  return m_transformation.toPoseArray();
}

std::array<float, 6> PivotTransform::getTrocarState() const {
  std::array<float, 6> state;
  for (int i = 0; i < 3; i++) {
    state[i]     = m_pivot_point_position[i];
    state[i + 3] = m_pivot_point_orientation[i];
  }

  return state;
}

std::array<float, 7> PivotTransform::getTrocarPose() const {
  HomogeneousMatrix trocar_transformation = {m_pivot_point_orientation, m_pivot_point_position, m_is_degree};

  return trocar_transformation.toPoseArray();
}

bool PivotTransform::rotationIsValid() const {
  return m_transformation.rotationMatrixIsValid();
}

RotationMatrix PivotTransform::getRotationMatrix() const {
  return m_transformation.getRotationMatrix();
}

std::array<float, 3> PivotTransform::getTranslationVector() const {
  return m_transformation.getTranslationVector();
}

std::array<float, 3> PivotTransform::getZVector() const {
  RotationMatrix rotation  = m_transformation.getRotationMatrix();
  std::array<float, 3> vec = {rotation[0][2], rotation[1][2], rotation[2][2]};
  float norm               = std::sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
  vec[0] /= norm;
  vec[1] /= norm;
  vec[2] /= norm;

  return vec;
}

////********************* help_function for debug ***************************////
//void PivotTransform::print() const {
//    m_transformation.print();
//}
//
//HomogeneousMatrix PivotTransform::getM_transformation() const {
//    return m_transformation;
//}
