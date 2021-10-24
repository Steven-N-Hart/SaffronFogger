import unittest
from functions import pubsub1 as ps1

class MyTestCase(unittest.TestCase):
    def test_something(self):
        event={'@type': 'type.googleapis.com/google.pubsub.v1.PubsubMessage', 'attributes': {'deviceId': 'esp8266-1', 'deviceNumId': '2648057625773227', 'deviceRegistryId': 'io-hydro-registry', 'deviceRegistryLocation': 'us-central1', 'projectId': 'io-hydro', 'subFolder': ''}, 'data': 'eyAiSVBBZGQiOiAiMTkyLjE2OC4xLjE5IiwgIlRpbWUiOiAxNjM1MDQ5OTAxLCAiV2F0ZXJUZW1wIjogLTEyNy4wMCwgIkFpclRlbXBUb3AiOiAwLjAwLCAiQWlyVGVtcEJvdCI6IDAuMDAsICJSZWxIdW1Ub3AiOiAwLjAwLCAiUmVsSHVtQm90IjogMC4wMCwgIkxpcXVpZExldmVsIjogMi4wMCwgIlBQTSI6IC00LjEyLCAidXBkYXRlVGltZV9tcyI6IDUwMDAsICJmb2dnZXJfaHVtaWRfb2ZmIjogODAuMDAsICJmb2dnZXJfaHVtaWRfb24iOiA3MC4wMCwgIm1heF9mb2dnZXJfb25fbXMiOiAxMDAgfQ=='}
        res = ps1.pubsub_to_bigq(event, None)

        self.assertEqual(True, False)  # add assertion here


if __name__ == '__main__':
    unittest.main()
