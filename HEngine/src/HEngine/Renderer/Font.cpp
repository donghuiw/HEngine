#include "hepch.h"
#include "Font.h"

#undef INFINITE
#include "msdf-atlas-gen.h"

namespace HEngine
{
	Font::Font(const std::filesystem::path& filepath)
	{
		msdfgen::FreetypeHandle* ft = msdfgen::initializeFreetype();		//初始化Freetype引擎
		if (ft)
		{
			std::string fileString = filepath.string();
			msdfgen::FontHandle* font = msdfgen::loadFont(ft, fileString.c_str());		//加载字体文件
			if (font)
			{
				msdfgen::Shape shape;
				if (msdfgen::loadGlyph(shape, font, 'C'))			//加载字符 'C' 的形状数据到 shape 变量
				{
					shape.normalize();		//将字符轮廓缩放到一个标准的范围

					//														max		  angle
					msdfgen::edgeColoringSimple(shape, 3.0);
					//								image          width    height
					msdfgen::Bitmap<float, 3> msdf(32, 32);
					//											  range  scale    translation
					msdfgen::generateMSDF(msdf, shape, 4.0, 1.0, msdfgen::Vector2(4.0, 4.0));
					msdfgen::savePng(msdf, "output.png");
				}
				msdfgen::destroyFont(font);
			}
			msdfgen::deinitializeFreetype(ft);
		}
	}
}

