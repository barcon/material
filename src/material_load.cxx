#include "material_load.hpp"
#include "material_properties.hpp"
#include "material_properties_scalar.hpp"
#include "material_properties_string.hpp"
#include "material_properties_interpolation.hpp"

#include "tinyxml2.h"

namespace material
{
	MaterialSolidPtr LoadMaterialSolidXML(Tag tag, String fileName, Status& status)
	{
		auto res = CreateMaterialSolid(tag);

		tinyxml2::XMLDocument file;
		tinyxml2::XMLNode* pRoot{ nullptr };
		tinyxml2::XMLElement* pProperty{ nullptr };
		tinyxml2::XMLElement* pName{ nullptr };
		tinyxml2::XMLElement* pKey{ nullptr };
		tinyxml2::XMLElement* pUnit{ nullptr };
		tinyxml2::XMLElement* pValue{ nullptr };

		IPropertyPtr prop{ nullptr };

		file.LoadFile(fileName.c_str());

		pRoot = file.RootElement();
		if (pRoot == nullptr)
		{
			status = tinyxml2::XML_ERROR_FILE_READ_ERROR;
			return nullptr;
		}

		pProperty = pRoot->FirstChildElement("property");
		if (pProperty == nullptr)
		{
			status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
			return nullptr;
		}

		while (pProperty != nullptr)
		{
			pName = pProperty->FirstChildElement("name");
			if (pName == nullptr)
			{
				status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
				return nullptr;
			}

			pKey = pProperty->FirstChildElement("key");
			if (pKey == nullptr)
			{
				status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
				return nullptr;
			}

			pUnit = pProperty->FirstChildElement("unit");
			if (pUnit == nullptr)
			{
				status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
				return nullptr;
			}

			if (String(pProperty->Attribute("type")) == "String")
			{
				pValue = pProperty->FirstChildElement("value");
				if (pValue == nullptr)
				{
					status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
					return nullptr;
				}

				prop = CreatePropertyString(String(pName->GetText()), String(pKey->GetText()), String(pValue->GetText()));
			}
			else if (String(pProperty->Attribute("type")) == "Scalar")
			{		
				Scalar value;

				pValue = pProperty->FirstChildElement("value");
				if (pValue == nullptr)
				{
					status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
					return nullptr;
				}

				pValue->QueryDoubleText(&value);

				prop = CreatePropertyScalar(String(pName->GetText()), String(pKey->GetText()), value);
			}
			else
			{
				status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
				return nullptr;
			}

			if (prop->GetKey() == "class")
			{
				res->SetClass(std::dynamic_pointer_cast<IPropertyString>(prop));
			}
			else if (prop->GetKey() == "group")
			{
				res->SetGroup(std::dynamic_pointer_cast<IPropertyString>(prop));
			}
			else if (prop->GetKey() == "description")
			{
				res->SetDescription(std::dynamic_pointer_cast<IPropertyString>(prop));
			}
			else if (prop->GetKey() == "name")
			{
				res->SetName(std::dynamic_pointer_cast<IPropertyString>(prop));
			}
			else if (prop->GetKey() == "rho")
			{
				res->SetDensity(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "nu")
			{
				res->SetPoissonRatio(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "cp")
			{
				res->SetSpecificHeat(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "k")
			{
				res->SetThermalConductivity(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "alpha")
			{
				res->SetThermalExpansion(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "E")
			{
				res->SetElasticModulus(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "Rm")
			{
				res->SetTensileStrength(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "Re")
			{
				res->SetYieldStrength(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "tau_B")
			{
				res->SetShearStrength(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "p_G")
			{
				res->SetLimitingSurfacePressure(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}

			pProperty = pProperty->NextSiblingElement("property");
		}

		status = tinyxml2::XML_SUCCESS;
		return res;
	}
	MaterialFluidPtr LoadMaterialFluidXML(Tag tag, String fileName, Status& status)
	{
		auto res = CreateMaterialFluid(tag);

		tinyxml2::XMLDocument file;
		tinyxml2::XMLNode* pRoot{ nullptr };
		tinyxml2::XMLElement* pProperty{ nullptr };
		tinyxml2::XMLElement* pName{ nullptr };
		tinyxml2::XMLElement* pKey{ nullptr };
		tinyxml2::XMLElement* pUnit{ nullptr };
		tinyxml2::XMLElement* pMethod{ nullptr };
		tinyxml2::XMLElement* pValue{ nullptr };
		
		String method;
		IPropertyPtr prop{ nullptr };

		file.LoadFile(fileName.c_str());

		pRoot = file.RootElement();
		if (pRoot == nullptr)
		{
			status = tinyxml2::XML_ERROR_FILE_READ_ERROR;
			return nullptr;
		}

		pProperty = pRoot->FirstChildElement("property");
		if (pProperty == nullptr)
		{
			status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
			return nullptr;
		}

		while (pProperty != nullptr)
		{
			pName = pProperty->FirstChildElement("name");
			if (pName == nullptr)
			{
				status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
				return nullptr;
			}

			pKey = pProperty->FirstChildElement("key");
			if (pKey == nullptr)
			{
				status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
				return nullptr;
			}

			pUnit = pProperty->FirstChildElement("unit");
			if (pUnit == nullptr)
			{
				status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
				return nullptr;
			}

			if (String(pProperty->Attribute("type")) == "String")
			{
				pValue = pProperty->FirstChildElement("value");
				if (pValue == nullptr)
				{
					status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
					return nullptr;
				}

				prop = CreatePropertyString(String(pName->GetText()), String(pKey->GetText()), String(pValue->GetText()));
			}
			else if (String(pProperty->Attribute("type")) == "Scalar")
			{
				Scalar value;

				pValue = pProperty->FirstChildElement("value");
				if (pValue == nullptr)
				{
					status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
					return nullptr;
				}

				pValue->QueryDoubleText(&value);

				prop = CreatePropertyScalar(String(pName->GetText()), String(pKey->GetText()), value);
			}
			else if (String(pProperty->Attribute("type")) == "Interpolation")
			{	
				interpolation::NodePtr node;
				interpolation::Nodes nodes;

				pMethod = pProperty->FirstChildElement("method");
				if (pMethod == nullptr)
				{
					status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
					return nullptr;
				}

				method = String(pMethod->GetText());

				for (pValue = pProperty->FirstChildElement("value"); pValue != nullptr; pValue = pValue->NextSiblingElement("value"))
				{
					Matrix value(1, 1);
					Scalar temperature;
					Scalar pressure;

					pValue->QueryDoubleAttribute("temperature", &temperature);
					pValue->QueryDoubleAttribute("pressure", &pressure);
					pValue->QueryDoubleText(&value(0, 0));

					node = node::Create(temperature, pressure, 0.0, value);
					nodes.push_back(node);
				}

				if (method == "FIXED")
				{
					prop = CreatePropertyInterpolation(String(pName->GetText()), String(pKey->GetText()), interpolation::interpolation_fixed, nodes);
				}
				else if (method == "NN")
				{
					prop = CreatePropertyInterpolation(String(pName->GetText()), String(pKey->GetText()), interpolation::interpolation_nn, nodes);
				}
				else if (method == "IDW")
				{
					prop = CreatePropertyInterpolation(String(pName->GetText()), String(pKey->GetText()), interpolation::interpolation_idw, nodes);
				}
				else if (method == "RBF")
				{
					prop = CreatePropertyInterpolation(String(pName->GetText()), String(pKey->GetText()), interpolation::interpolation_rbf, nodes);
				}
			}
			else
			{
				status = tinyxml2::XML_ERROR_PARSING_ELEMENT;
				return nullptr;
			}

			if (prop->GetKey() == "class")
			{
				res->SetClass(std::dynamic_pointer_cast<IPropertyString>(prop));
			}
			else if (prop->GetKey() == "group")
			{
				res->SetGroup(std::dynamic_pointer_cast<IPropertyString>(prop));
			}
			else if (prop->GetKey() == "description")
			{
				res->SetDescription(std::dynamic_pointer_cast<IPropertyString>(prop));
			}
			else if (prop->GetKey() == "name")
			{
				res->SetName(std::dynamic_pointer_cast<IPropertyString>(prop));
			}
			else if (prop->GetKey() == "rho")
			{
				res->SetDensity(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "mu")
			{
				res->SetDynamicViscosity(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "cp")
			{
				res->SetSpecificHeat(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}
			else if (prop->GetKey() == "k")
			{
				res->SetThermalConductivity(std::dynamic_pointer_cast<IPropertyScalar>(prop));
			}

			pProperty = pProperty->NextSiblingElement("property");
		}

		status = tinyxml2::XML_SUCCESS;
		return res;
	}
} // namespace material