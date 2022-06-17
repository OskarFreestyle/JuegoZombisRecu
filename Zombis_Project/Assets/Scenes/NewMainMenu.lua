local level = {
    ambient="1.0,1.0,1.0",
    gravity="0.0,0.0,0.0",
    camera = {
        nearClipDistance="1",
        farClipDistance="10000",
        camPosition="0,2500,0",
        camRotation="0.0,0.0,0.0"
    },
    entidades = {
        {
            name="Camera",
            id=0,
            components={
                transform={
                    position="0,0,0",
                    rotation="0,0,0",
                    scale="1,1,1",
                    parent="-1"
                },
                camera={
                    near="0.1",
                    far="1000",
                    autoaspect="true",
                    aspect="1.78",
                    fov="50",
                    proyection="1",
                    viewport="0,0,1,1",
                    color="0,0.5,0.5"
                }
            }
        }, 
        {
            name="BotonPlay",
            id=1,
            components={
                transform={
                    parent="-1",
                    position="0.10,0.375,-10",
                    rotation="0,0,0",
                    scale="1.0,1.0,1.0"
                },
                mesh={
                    mesh="ninja.mesh",
                    material="",
                    visible="true"
                }
            }
        }
    }
}

function GetLevel ()
  return level
end

