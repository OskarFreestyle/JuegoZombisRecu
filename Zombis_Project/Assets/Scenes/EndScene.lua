local endScene = {
    backgroundColor="0.6,1.0,0.0",
    ambient="0.1,0.1,0.1",
    gravity="0 -9.8 0",
    botones={
		
		{
			positionX="0.25",
			positionY="0.75",
			texto="Back To Menu",
			nombrePanel="BackMenuPanel",
			nombreTexto="BackMenuTexto",
			tamLetra="0.05",
			material="Azul",
			dimensionX="0.25",
			dimensionY="0.25"
			
			
		}
		
		
    },
	
}

function GetEndScene ()
  return endScene
end

function pruebaTexto()
    print('Im Working YESS')
end

