local level = {
    ambient="1.0,1.0,1.0",
    gravity="0.0,0.0,0.0",
    entidades = {
        {
            name="Camera",
            id=0,
            components={
                transform={
                    position="0,2000,0",
                    rotation="-90,0,0",
                    scale="1,1,1",
                    parent="-1"
                },
                camera={
                    near="0.1",
                    far="3000",
                    autoaspect="true",
                    aspect="1.78",
                    fov="50",
                    proyection="1",
                    viewport="0,0,1,1",
                    color="0.2,0.2,0"
                }
            }
        }, 
        {
			name="BackGroundImage",
            id=1,
            components={
				image={
					positionX="0",
					positionY="0",
					nombrePanel="BackGroundPanel",
					material="OptionsMenuBG",
					dimensionX="1",
					dimensionY="1"
				}
            }
            
        },
		{
            name="BotonBack",
            id=2,
            components={
				button={
					positionX="0.55",
					positionY="0.15",
					texto="Return",
					nombrePanel="ReturnPanel",
					nombreTexto="ReturnTexto",
					tamLetra="0.05",
					material="LapidaButton",
					dimensionX="0.25",
					dimensionY="0.35",
					type="CHANGE_SCENE",
					nextScene="MainMenuScene.lua"
				}
            }
        },
		{
			name="BotonVolume",
            id=3,
            components={
				button={
					positionX="0.2",
					positionY="0.2",
					texto="",
					nombrePanel="VolumePanel",
					nombreTexto="VolumeTexto",
					tamLetra="0.1",
					material="AltavozButton",
					dimensionX="0.25",
					dimensionY="0.25",
					type="VOLUME",
					nextScene=" "
				}
            }
		}
		
    }
}

function GetLevel ()
  return level
end