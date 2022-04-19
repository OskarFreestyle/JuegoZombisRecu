local level = {
  entidades = {
    {
      name="Player",
      id=1,
      components={
        transform={
          position="0,-90,0",
          rotation="0,0,0",
          scale="1,1,1",
          parent="-1"
        },
        renderer={
          mesh="Sinbad.mesh",
          material="",
          visible="true"
        }
      }
    }
  }
}

function GetMapa ()
  return mapa
end

