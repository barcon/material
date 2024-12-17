#ifndef MATERIAL_TYPES_HPP_
#define MATERIAL_TYPES_HPP_

#include "utils.hpp"
#include "logger.hpp"
#include "eilig.hpp"
#include "values.hpp"

#include <memory>
#include <variant>
#include <unordered_map>

namespace material
{
	using Scalar = eilig::Scalar;
	using Scalars = eilig::Scalars;
	using Matrix = eilig::Matrix;
	using Matrices = eilig::Matrices;

	using String = utils::String;
	using Strings = utils::Strings;

	using IStringPtr = values::IStringPtr;
	using IScalar1DPtr = values::IScalar1DPtr;
	using IScalar2DPtr = values::IScalar2DPtr;
	using IScalar3DPtr = values::IScalar3DPtr;
	
	using Tag = std::size_t;
	using Type = std::size_t;
	using Status = long long int;

	const String materialLogger = "MATERIAL";

} // namespace material

#endif /* MATERIAL_TYPES_HPP_*/