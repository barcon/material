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

	using IValuePtr = values::IValuePtr;
	using IBoolPtr = values::IBoolPtr;
	using IStringPtr = values::IStringPtr;
	using IScalarPtr = values::IScalarPtr;
	using IScalar1DPtr = values::IScalar1DPtr;
	using IScalar2DPtr = values::IScalar2DPtr;
	using IScalar3DPtr = values::IScalar3DPtr;
	using IVectorPtr = values::IVectorPtr;
	using IVector3DPtr = values::IVector3DPtr;
	using IMatrixPtr = values::IMatrixPtr;
	using IMatrix3DPtr = values::IMatrix3DPtr;
	
	using Properties = std::unordered_map<String, IValuePtr>;

	using Tag = std::size_t;
	using Type = std::size_t;
	using Status = long long int;

	const String materialLogger = "MATERIAL";

} // namespace material

#endif /* MATERIAL_TYPES_HPP_*/