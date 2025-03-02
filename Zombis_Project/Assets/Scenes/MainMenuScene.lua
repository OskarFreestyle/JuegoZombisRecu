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
            name="MainMusic",
            id=6,
            components={
                audioSource={
					audioFileName="GameMusicShort.mp3",
					channel="0",
					loop="true",
					startOnPlay="true"
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
					material="MainMenuBG",
					dimensionX="1",
					dimensionY="1"
				}
            }
        },
		{
            name="BotonOptions",
            id=2,
            components={
				button={
					positionX="0.375",
					positionY="0.375",
					texto="Options",
					nombrePanel="OptionsPanel",
					nombreTexto="OptionsTexto",
					tamLetra="0.05",
					material="LapidaButton",
					dimensionX="0.25",
					dimensionY="0.35",
					type="CHANGE_SCENE",
					nextScene="OptionsScene.lua",
					clickDelay="300"
				},
				audioSource={
					audioFileName="click.mp3",
					channel="1",
					loop="false",
					startOnPlay="false"
				}
            }
        },
		{
			name="BotonExit",
            id=3,
            components={
				button={
					positionX="0.65",
					positionY="0.375",
					texto="Exit",
					nombrePanel="ExitPanel",
					nombreTexto="ExitTexto",
					tamLetra="0.05",
					material="LapidaButton",
					dimensionX="0.25",
					dimensionY="0.35",
					type="EXIT",
					nextScene="",
					clickDelay="300"
				},
				audioSource={
					audioFileName="click.mp3",
					channel="1",
					loop="false",
					startOnPlay="false"
				}
            }
		},
		{
			name="BotonPlay",
            id=4,
            components={
				button={
					positionX="0.10",
					positionY="0.375",
					texto="Play",
					nombrePanel="NewGamePanel",
					nombreTexto="NewGameTexto",
					tamLetra="0.05",
					material="LapidaButton",
					dimensionX="0.25",
					dimensionY="0.35",
					type="CHANGE_SCENE",
					nextScene="PlayScene.lua",
					clickDelay="300"
				},
				audioSource={
					audioFileName="click.mp3",
					channel="1",
					loop="false",
					startOnPlay="false"
				}
            }
		}
    }
}

function GetLevel ()
  return level
end

