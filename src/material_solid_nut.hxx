#ifndef MATERIAL_SOLID_NUT_HPP_
#define MATERIAL_SOLID_NUT_HPP_

#include "material_solid.hpp"

namespace material
{
	class MaterialNut;
	using MaterialNutPtr = std::shared_ptr< MaterialNut >;
	using ConstMaterialNutPtr = std::shared_ptr< const MaterialNut >;
	
	MaterialNutPtr CreateMaterialNut(Tag tag, String grade, Scalar diameter);

	class MaterialNut : public MaterialSolid, virtual public std::enable_shared_from_this<MaterialNut>
	{
	public:
		virtual ~MaterialNut() = default;

		static MaterialNutPtr Create();
		MaterialNutPtr GetPtr();
		ConstMaterialNutPtr GetPtr() const;

		void SetGrade(String grade);
		void SetDiameter(Scalar diameter);

	protected:
		MaterialNut();

		void UpdateProperties();

		Scalar T_ref{ 293.15 };
		Scalar p_ref{ 101325.0 };

		IPropertyStringPtr grade_{ nullptr };
		IPropertyScalarPtr diameter_{ nullptr };

		using std::enable_shared_from_this<MaterialNut>::shared_from_this;
	};
} // namespace material

#endif /* MATERIAL_SOLID_NUT_HPP_*/