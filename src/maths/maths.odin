package maths

import "core:math"
import "core:math/big"
import "core:math/bits"
import "core:math/cmplx"
import "core:math/ease"
import "core:math/fixed"
import "core:math/linalg"
import "core:math/noise"
import "core:math/rand"

Mat4 :: linalg.Matrix4x4f32

@(export, link_prefix = "maths_")
Perspective :: proc "c" (fov, apsect, near, far: f32, flip_z: bool) -> Mat4 {
	return linalg.matrix4_perspective_f32(fov, apsect, near, far, flip_z)
}

@(export, link_prefix = "maths_")
Orthogonal :: proc "c" (left, right, bottom, top, near, far: f32, flip_z: bool) -> Mat4 {
	return linalg.matrix_ortho3d_f32(left, right, bottom, top, near, far, flip_z)
}
