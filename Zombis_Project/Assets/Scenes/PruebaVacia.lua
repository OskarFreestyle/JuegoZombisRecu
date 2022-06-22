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
                }
            }
        } 
        
		
    }
}

function GetLevel ()
  return level
end