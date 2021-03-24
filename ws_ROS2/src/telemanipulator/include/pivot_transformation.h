#pragma once
#include "homogeneous_matrix.h"

class PivotTransform {
 private:
  float m_pan;    // rotation around y
  float m_tilt;   // rotation around x
  float m_spin;   // rotation around z
  float m_depth;  // translation along z
  bool m_is_degree;

  std::array<float, 3> m_pivot_point_position;     // translation x, y, z
  std::array<float, 3> m_pivot_point_orientation;  // rotation x, y, z

  // The link between pose and state space
  HomogeneousMatrix m_transformation;

  // Update m_transformation from the stored values for m_pan, m_tilt, etc.
  void updateTransformation();

 public:
  PivotTransform(
      const float pan,
      const float tilt,
      const float spin,
      const float depth,
      const std::array<float, 3> &pivot_point_position,
      const std::array<float, 3> &pivot_point_orientation,
      const bool is_degree);

  PivotTransform();

  void updateTransformationRelative(const float delta_pan,
                                    const float delta_tilt,
                                    const float delta_spin,
                                    const float delta_depth);

  void updateTransformationAbsolute(const float new_pan,
                                    const float new_tilt,
                                    const float new_spin,
                                    const float new_depth);

  void pan(const float delta_pan);
  void tilt(const float delta_tilt);
  void spin(const float delta_spin);
  void insert(const float delta_insert);

  void updateTrocarPoseRelative(const std::array<float, 3> &delta_pivot_point_position,
                                const std::array<float, 3> &delta_pivot_point_orientation);

  void updateTrocarPoseAbsolute(const std::array<float, 3> &new_pivot_point_position,
                                const std::array<float, 3> &new_pivot_point_orientation);

  bool rotationIsValid() const;

  RotationMatrix getRotationMatrix() const;
  std::array<float, 3> getTranslationVector() const;

  // Getter for the pivotized tool
  std::array<float, 4> getPivotState() const;
  std::array<float, 7> getPivotPose() const;

  // Getter for the trocar
  /* x, y, z, rotation_x, rotation_y, rotation_z */
  std::array<float, 6> getTrocarState() const;
  std::array<float, 7> getTrocarPose() const;

  // Get the vector that points along the z axis of the transformation
  std::array<float, 3> getZVector() const;
//
//  void print() const;
//
//  HomogeneousMatrix getM_transformation() const;
};

