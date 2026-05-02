#ifndef MATERIAL_TYPES_HPP_
#define MATERIAL_TYPES_HPP_

#include "utils.hpp"
#include "logger.hpp"
#include "eilig.hpp"
#include "value.hpp"

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

	using IValuePtr = value::IValuePtr;
	using IBoolPtr = value::IBoolPtr;
	using IStringPtr = value::IStringPtr;

	using IScalarPtr = value::IScalarPtr;
	using IVectorPtr = value::IVectorPtr;
	using IMatrixPtr = value::IMatrixPtr;

	using IScalarCoordinatesPtr = value::IScalarCoordinatesPtr;
	using IVectorCoordinatesPtr = value::IVectorCoordinatesPtr;
	using IMatrixCoordinatesPtr = value::IMatrixCoordinatesPtr;
	
	using Properties = std::unordered_map<String, IValuePtr>;

	using Tag = std::size_t;
	using Status = long long int;

	const String headerMaterial = "MATERIAL";

	using Type = std::size_t;
	static const Type material_solid = 1;
	static const Type material_fluid = 2;

} // namespace material

#endif /* MATERIAL_TYPES_HPP_*/