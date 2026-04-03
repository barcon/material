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
	using Vector = eilig::Vector;
	using Vectors = eilig::Vectors;
	using Matrix = eilig::Matrix;
	using Matrices = eilig::Matrices;

	using String = utils::String;
	using Strings = utils::Strings;

	using IValuePtr = values::IValuePtr;
	using IBoolPtr = values::IBoolPtr;
	using IStringPtr = values::IStringPtr;

	using IScalarPtr = values::IScalarPtr;
	using IVectorPtr = values::IVectorPtr;
	using IMatrixPtr = values::IMatrixPtr;

	using IScalarCoordinatesPtr = values::IScalarCoordinatesPtr;
	using IVectorCoordinatesPtr = values::IVectorCoordinatesPtr;
	using IMatrixCoordinatesPtr = values::IMatrixCoordinatesPtr;
	
	using Properties = std::unordered_map<String, IValuePtr>;

	using Tag = std::size_t;
	using Type = std::size_t;
	using Status = long long int;

	const String headerMaterial = "MATERIAL";
} // namespace material

#endif /* MATERIAL_TYPES_HPP_*/