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
            name="BotonBack",
            id=1,
            components={
				button={
					positionX="0.75",
					positionY="0.65",
					texto="Menu",
					nombrePanel="BackMenuPanel",
					nombreTexto="BackMenuTexto",
					tamLetra="0.05",
					material="LapidaButton",
					dimensionX="0.25",
					dimensionY="0.35",
					type="CHANGE_SCENE",
					nextScene="NewMainMenu.lua"
				}
            }
        },
		{
			name="GameOver",
            id=2,
            components={
				texto={
					positionX="0.2",
					positionY="0.1",
					texto="GAME OVER",
					nombreTexto="GameOverText",
					tamLetra="0.1",
					nombrePanel="GameOverPanel",
					dimensionX="0.6",
					dimensionY="0.3",
					color="Red"
				}
            }
		}
		
    }
}

function GetLevel ()
  return level
end