function Decoder(bytes, port) {
	var decoded = {};
  
	var msg = String.fromCharCode.apply(null, bytes);
	  var i = 1; 
	  var deviceId = '';
	  var dumpsterFilingPercentage = '';
	  var batteryStatus = '';
  
	  while(i < msg.length && msg[i] != "P")
	  {
		  deviceId += msg[i];
		i++;
	  }
	decoded.deviceId = deviceId;
  
	i++;
	  
	  while(i < msg.length && msg[i] != "B")
	  {
		  dumpsterFilingPercentage += msg[i];
		i++;
	  }
	decoded.dumpsterFilingPercentage = dumpsterFilingPercentage;
	
	i++;
	
	while(i < msg.length)
	  {
		  batteryStatus += msg[i];
		i++;
	  }
	decoded.batteryStatus = batteryStatus;
	
	return decoded;
  }