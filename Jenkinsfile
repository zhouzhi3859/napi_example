pipeline {
  agent {
    label 'SWARM-NODE-NODEJS:DOCKER'
  }
  stages {
    stage('build') {
      steps {
        sh '''
          export VERSION=`npm run packageVersion | awk 'END{print}'`
          echo "version = ${VERSION}"
          npm install
          npm run build
          npm run package
          npm run publish
        '''
      }
    }
  }
}
